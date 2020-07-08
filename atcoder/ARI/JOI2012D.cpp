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

int D, N;
vector<int> T;
vector<int> A, B, C;

vector<vector<int>> dp(210, vector<int>(110, -1));

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> D >> N;
    T.resize(D);
    for (int i = 0; i < D; i++) {
        cin >> T[i];
    }
    A.resize(N);
    B.resize(N);
    C.resize(N);

    REP(i, N) {
        cin >> A[i] >> B[i] >> C[i];
    }

    for (int i = 0; i < N; i++) {
        if (A[i] <= T[0] && T[0] <= B[i]) {
            chmax(dp[0][C[i]], 0);
        }
    }

    for (int i = 1; i < D; i++) {
        for (int j = 0; j < N; j++) {
            if (A[j] <= T[i] && T[i] <= B[j]) {
                for (int c : C) {
                    if (dp[i-1][c] != -1) {
                        chmax(dp[i][C[j]], dp[i-1][c] + abs(C[j] - c));
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 101; i++) {
        chmax(ans, dp[D - 1][i]);
    }

    cout << ans << endl;





    return 0;
}