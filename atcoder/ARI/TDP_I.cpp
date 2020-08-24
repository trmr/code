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

string s;
vector<vector<int>> dp(310, vector<int>(310));

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> s;

    for (int len = 3; len < s.size(); len++) {
        for (int l = 0; l + len < s.size(); l++) {
            int r = l + len;

            if (len == 3) {
                if (s.substr(l, 3) == "iwi") {
                    dp[l][l + 2] = 3;
                }
                continue;
            }

            if ((s.substr(l, 2) == "iw") && (s.substr(r, 1) == "i") && dp[l+2][r - 1] == r - l - 2) {
                dp[l][r] = r - l + 1;
            } else if ((s.substr(l, 1) == "i") && (s.substr(r - 1, 2) == "wi") && dp[l+1][r-2] == r - l - 2) {
                dp[l][r] = r - l + 1;
            }

            for (int m = l; m < r; m++) {
                dp[l][r] = max(dp[l][r], dp[l][m] + dp[m + 1][r]);
            }


        }
    }

    cout << dp[0][s.size() - 1] / 3 << endl;


    return 0;
}