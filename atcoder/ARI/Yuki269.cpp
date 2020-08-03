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

ll N, S, K;
VVL dp;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> S >> K;

    dp.assign(N+1, VL(S+1));

    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= S; j++) {
            if (i && j >= K * (N - i)) {
                dp[i][j] += dp[i - 1][j - K * (N - i)];
                dp[i][j] %= mod;
            }
            if (j >= N - i) {
                dp[i][j] += dp[i][j - (N - i)];
                dp[i][j] %= mod;
            }
        }
    }

    cout << dp[N-1][S] << endl;






    return 0;
}