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

vector<vector<ll>> dp(110, vector<ll>(10100));
vector<ll> p;
int N;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    p.resize(N);

    REP(i, N) cin >> p[i];

    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 10000; j++) {
            if (j >= p[i]) {
                dp[i + 1][j] = dp[i][j] + dp[i][j - p[i]];
            } else {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }

    ll ans = 0;

    for (int i = 0; i <= 10000; i++) {
        if (dp[N][i] != 0) ans++;
    }

    cout << ans << endl;

    return 0;
}