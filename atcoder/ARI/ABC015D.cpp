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

int W;
int N, K;
vector<int> A, B;

vector<vector<vector<int>>> dp(51, vector<vector<int>>(51, vector<int>(10010)));

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> W;
    cin >> N >> K;
    A.resize(N);
    B.resize(N);

    REP(i, N) {
        cin >> A[i] >> B[i];
    }

    for (int i = 0; i <= N; i++) {
        dp[0][i][0] = 0;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k <= W; k++) {
                if (k >= A[i]) {
                    dp[i + 1][j + 1][k] = max(dp[i][j][k], dp[i][j][k - A[i]] + B[i]);
                    dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j + 1][k]);
                } else {
                    dp[i + 1][j + 1][k] = max(dp[i][j][k], dp[i][j + 1][k]);
                }
            }
        }
    }

    cout << dp[N][K][W] << endl;


    return 0;
}