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

int N, W;
vector<ll> w;
vector<ll> v;
vector<vector<ll>> dp(110, vector<ll>(100100, INF));

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> W;

    w.resize(N + 1);
    v.resize(N + 1);

    REP(i, N) {
        cin >> w[i + 1] >> v[i + 1];
    }

    dp[0][0] = 0;
    

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 100100; j++) {
            if (v[i] <= j) {
                chmin(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
            }
            chmin(dp[i][j], dp[i - 1][j]);
        }
    }

    int ans = 0;

    for (int i = 0; i < 100100; i++) {
        if (dp.at(N).at(i) <= W) {
            chmax(ans, i);
        }
    }

    cout << ans << endl;
    
    return 0;
}