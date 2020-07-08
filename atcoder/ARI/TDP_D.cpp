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

#define FOR(i, s, n) for (int i = s; i < (n); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const long long INF = 1LL<<60;
const int mod = 1000000007;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; i++) {
        if (N % i == 0) return false;
    }
    return true;
}

vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            res.push_back(i);
            if (N / i != i) res.push_back(N / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

vector<pair<long long, long long>> prime_factorize(long long N) {
    vector<pair<long long, long long>> res;
    for (long long a = 2; a * a <= N; a++) {
        if (N % a != 0) continue;
        long long ex = 0;

        while (N % a == 0) {
            ex++;
            N /= a;
        }

        res.push_back({a, ex});
    }

    if (N != 1) res.push_back({N, 1});
    return res;
}

int N;
ll D;

int dx[6] = {0, 1, 0, 2, 0, 1};
int dy[6] = {0, 0, 1, 0, 0, 1};
int dz[6] = {0, 0, 0, 0, 1, 0};

vector<vector<vector<vector<double>>>> dp;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> D;
    vector<pair<long long, long long>> pf = prime_factorize(D);
    ll A = 0, B = 0, C = 0;
    for (auto p:pf) {
        if (p.first == 2) A = p.second;
        else if (p.first == 3) B = p.second;
        else if (p.first == 5) C = p.second;
    }

    dp.assign(N + 1, vector<vector<vector<double>>>(A + 1, vector<vector<double>>(B + 1, vector<double>(C + 1))));
    dp[0][0][0][0] = (double)1;

    for (int round = 0; round < N; round++) {
        for (ll x = 0; x <= A; x++) {
            for (ll y = 0; y <= B; y++) {
                for (ll z = 0; z <= C; z++) {
                    for (int i = 0; i < 6; i++) {
                        int nx = min(A, x + dx[i]);
                        int ny = min(B, y + dy[i]);
                        int nz = min(C, z + dz[i]);
                        dp[round + 1][nx][ny][nz] += dp[round][x][y][z] / 6;
                    }
                }
            }
        }
    }

    cout << fixed << setprecision(9) << dp[N][A][B][C] << endl;
    






    return 0;
}