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

ll N, K;
vector<ll> a;

vector<vector<ll>> dp;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    a.resize(N + 1);
    dp.assign(N + 1, vector<ll>(N + 1, INF));

    REP(i, N) {
        cin >> a[i];
    }

    vector<ll> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i+1] += S[i] + a[i];
    }
    if (S[N] == K) {
        cout << 1 << endl;
        return 0;
    }

    dp[0][0] = 0;
    dp[1][1] = 1;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            ll b = max((ll)0, K - S[N] + S[i] - dp[i][j]);
            ll c = dp[i][j]*a[i]/S[i] + 1;

            if (c <= a[i]) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + max(b, c));
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + b);

        }
    }

    for (int i = N; i >= 0; i--) {
        if (dp[N][i] <= K) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}