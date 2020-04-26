#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using Field = vector<vector<int>>;
using Graph = vector<vector<int>>;
using VI = vector<int>;
using VC = vector<char>;
using PI = pair<int, int>;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const long long INF = 1LL<<60;
const int mod = 1000000007;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

const int MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i=2; i<MAX; i++) {
        fac[i] = fac[i-1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

ll COM(int n, int k) {
    if(n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}



ll modpow(ll a, ll n, int mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;

        n >>= 1;
    }
    return res;
}

ll nCr(int n, int r) {
    ll a = 1;
    ll b = 1;
    
    for (int i = 0; i < r; ++i) {
        a *= (n - i);
        b *= (i + 1);
        a %= mod;
        b %= mod;
    }
    return (a * modpow(b, mod - 2, mod))%mod;
}

ll N, K;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    ll ans = 0;

    for (ll i = K; i <= N + 1; i++) {
        ll min = (i - 1) * i / 2;
        ll max = i * (2 * N - i + 1) / 2;
        ll add = max - min + 1;
        ans = (ans + add) % mod;
    }

    cout << ans << endl;
    
    return 0;
}