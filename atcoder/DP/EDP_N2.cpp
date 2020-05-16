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

int N;
vector<ll> a;
vector<vector<ll>> dp;
vector<ll> S;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    a.resize(N);
    S.resize(N + 1);
    REP(i, N) cin >> a[i];
    dp.assign(N + 1, vector<ll>(N + 1, INF));

    for (int i = 0; i < N; i++) {
        dp[i][i] = 0;
    }

    S[0] = 0;
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + a[i];
    }

    for (int len = 1; len < N; len++) {
        for (int l = 0; l + len <= N; l++) {
            int r = l + len;
            for (int m = l; m < r; m++) {
                chmin(dp[l][r], dp[l][m] + dp[m + 1][r] + S[r + 1] - S[l]);
            }
        }
    }

    cout << dp[0][N - 1] << endl;
    
    return 0;
}