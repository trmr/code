#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Field = vector<vector<ll>>;
using Graph = vector<vector<ll>>;
using VI = vector<int>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VC = vector<char>;
using PI = pair<int, int>;
using PL = pair<ll, ll>;

#define FOR(i, s, n) for (int i = s; i < (n); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const long long INF = 1LL<<60;
const int MOD = 1000000007;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a / b * x;
    return d;
}

inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

long long modinv(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return mod(x, m);
}

using Graph = vector<vector<ll>>;

ll N;
Graph G;
vector<bool> seen;

PL rec(ll root) {
    seen[root] = true;

    vector<PL> ch;

    for (auto next : G[root]) {
        if (!seen[next]) {
            ch.push_back(rec(next));
        }
    }

    PL ret = make_pair((ll)1, 0);

    if (ch.size() != 0) {
        for (auto c : ch) {
            ret.first *= c.first;
            ret.first %= MOD;
            ret.first *= finv[c.second];
            ret.first %= MOD;
            ret.second += c.second;
        }
        ret.first *= fac[ret.second];
        ret.first %= MOD;
    }
    ret.second += 1;
    return ret;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    G.resize(N);


    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    ll ans = 0;

    COMinit();

    REP(i, N) {
        seen.assign(N, false);
        ans += rec(i).first;
        ans %= MOD;
    }

    cout << ans / 2 << endl;




    return 0;
}