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

int D;
string N;

vector<vector<vector<ll>>> dp(10010, vector<vector<ll>>(2, vector<ll>(110)));

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> D >> N;

    dp[0][1][0] = 1;

    

    for (int i = 0; i < (int)N.size(); i++) {
        for (int j = 0; j < 2; j++) {
            for (int d = 0; d < D; d++) {
                for (int k = 0; k < 10; k++) {
                    if (j == 0) {
                        dp[i + 1][j][(d + k)%D] += dp[i][j][d];
                        dp[i + 1][j][(d + k)%D] %= mod; 
                    } else {
                        if (k == (N[i] - '0')) {
                            dp[i+1][1][(d+k)%D] += dp[i][1][d];
                            dp[i+1][1][(d+k)%D] %= mod;
                        } else if (k < (N[i] - '0')) {
                            dp[i+1][0][(d+k)%D] += dp[i][1][d];
                            dp[i+1][0][(d+k)%D] %= mod;
                        }
                    }
                }
            }
        }
    }

    cout << (dp[(int)N.size()][0][0] + dp[(int)N.size()][1][0] + mod - 1) % mod << endl;

    return 0;
}