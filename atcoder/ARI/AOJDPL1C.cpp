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

vector<vector<int>> dp(110, vector<int>(10010));
int N, W;
vector<int> v(1000), w(1000);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> W;
    REP(i, N) {
        cin >> v[i] >> w[i];
    }

    for (int i = 0; i <= W; i++) {
        if (i >= w[0]) {
            chmax(dp[0][i], dp[0][i - w[0]] + v[0]);
        }

    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= W; j++) {
            if (j >= w[i]) {
                chmax(dp[i][j], dp[i - 1][j]);
                chmax(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
                chmax(dp[i][j], dp[i][j - w[i]] + v[i]);
            } else {
                chmax(dp[i][j],dp[i - 1][j]);
            }
        }
    }

    cout << dp[N - 1][W] << endl;



    return 0;
}