#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define FOR(i, n) for (int i = 0; i < n; i++)


int main() {
    int n, m; cin >> n >> m;
    string s = "abcd";
    string t = "becd";

    int dp[n+1][m+1];
    FOR(i, n){
        FOR (j, m) {
            if (s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    cout << dp[n][m] << endl;
    return 0;

}