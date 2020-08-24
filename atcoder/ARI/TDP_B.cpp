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

int A, B;
VI a, b;
vector<VI> dp;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> A >> B;
    a.resize(A+1);
    b.resize(B+1);

    REP(i, A) cin >> a[i];
    REP(i, B) cin >> b[i];

    dp.assign(A + 1, VI(B + 1));


    for (int i = A; i >= 0; i--) {
        for (int j = B; j >= 0; j--) {

            if (i == A && j == B) continue;

            if ((i + j) % 2 == 0) {
                if (i == A) {
                    dp[i][j] = dp[i][j + 1] + b[j];
                } else if (j == B) {
                    dp[i][j] = dp[i + 1][j] + a[i];
                } else {
                    dp[i][j] = max(dp[i][j + 1] + b[j], dp[i + 1][j] + a[i]);
                }
            } else {
                if (i == A) dp[i][j] = dp[i][j + 1];
                else if (j == B) dp[i][j] = dp[i + 1][j];
                else {
                    dp[i][j] = min(dp[i][j + 1], dp[i+1][j]);
                }
            }



        }
    }


    cout << dp[0][0] << endl;



    return 0;
}