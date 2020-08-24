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
const int MOD = 1000000007;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

ll N;
VL w;
VVL dp;
VL cost;
VVL K;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    w.resize(N + 1);
    cost.resize(N + 1);

    REP(i, N) { cin >> w[i];}

    for (int i = 1; i <= N; i++) {
        cost[i] = cost[i - 1] + w[i - 1];
    }

    dp.assign(N+1, VL(N+1, INF));
    K.assign(N+1, VL(N+1));

    REP(i, N + 1) {
        dp[i][i] = 0;
        K[i][i] = i;
    }

    for (int len = 1; len < N; len++) {
        for (int l = 0; l + len < N; l++) {
            int r = l + len;
            
            for (int m = K[l][r-1]; m <= K[l + 1][r]; m++) {

                if (dp[l][r] > dp[l][m] + dp[m+1][r] + cost[r + 1] - ((len>0)?cost[l]:0)) {
                    dp[l][r] = dp[l][m] + dp[m+1][r] + cost[r + 1] - ((len>0)?cost[l]:0);
                    K[l][r] = m;
                }
                
                
            }
        }
    }

    cout << dp[0][N-1] << endl;



    return 0;
}