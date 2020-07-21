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

int q;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> q;

    REP(_, q) {

        string A, B;
        vector<vector<int>> dp(1010, vector<int>(1010));

        cin >> A >> B;

        for (int i = 0; i < A.size(); i++) {
            if (A[i] == B[0]) dp[i][0] = 1;
            chmax(dp[i+1][0], dp[i][0]);
        }
        for (int i = 0; i < B.size(); i++) {
            if (A[0] == B[i]) dp[0][i] = 1;
            chmax(dp[0][i + 1], dp[0][i]);
        }
        
        for (int i = 1; i < A.size(); i++) {
            for (int j = 1; j < B.size(); j++) {
                if (A[i] == B[j]) {
                    chmax(dp[i][j], dp[i - 1][j - 1] + 1);
                } else {
                    chmax(dp[i][j], dp[i][j-1]);
                    chmax(dp[i][j], dp[i-1][j]);
                }
            }
        }



        cout << dp[A.size() - 1][B.size() - 1] << endl;


    }


    

    return 0;
}