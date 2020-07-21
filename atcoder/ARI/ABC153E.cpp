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

int H, N;
vector<int> A, B;
vector<vector<ll>> dp(1010, vector<ll>(10010, INF));

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> H >> N;
    A.resize(N); B.resize(N);
    REP(i, N) {
        cin >> A[i] >> B[i];
    }

    dp[0][0] = 0;



    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= H; j++) {
            chmin(dp[i + 1][j], dp[i][j]);
            if (j + A[i] >= H) {
                chmin(dp[i + 1][H], dp[i + 1][j] + B[i]);
            } else {
                chmin(dp[i + 1][j + A[i]], dp[i + 1][j] + B[i]);
            }

        }
    }

    cout << dp[N][H] << endl;



    return 0;
}