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
vector<int> a;
vector<int> b;
vector<int> c;
vector<ll> dp[3];


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    a.resize(N);
    b.resize(N);
    c.resize(N);
    REP(i, 3) dp[i].resize(N + 1);

    REP(i, N) {
        cin >> a.at(i) >> b.at(i) >> c.at(i);
    }

    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[2][0] = 0;

    for (int i = 0; i < N; i++) {
        dp[0][i + 1] = (dp[1][i] > dp[2][i]) ? dp[1][i] + a[i] : dp[2][i] + a[i];
        dp[1][i + 1] = (dp[0][i] > dp[2][i]) ? dp[0][i] + b[i] : dp[2][i] + b[i];
        dp[2][i + 1] = (dp[0][i] > dp[1][i]) ? dp[0][i] + c[i] : dp[1][i] + c[i];
    }

    ll ans = 0;
    REP(i, 3) {
        chmax(ans, dp[i][N]);
    }

    cout << ans << endl;

    return 0;
}