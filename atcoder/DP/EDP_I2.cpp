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
vector<double> p;
vector<vector<double>> dp(3010, vector<double>(10000));


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    p.resize(N);

    REP(i, N) cin >> p.at(i);

    dp[0][0] = 1.0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i + 1][j + 1] += dp[i][j]*p[i];
            dp[i + 1][j] += dp[i][j]*(1.0 - p[i]);
        }
    }

    double ans = 0;
    for (int i = 0; i < (N+1)/2; i++) {
        ans += dp[N][i];
    }

    cout << setprecision(10) << (double)1.0 - ans << endl;
    
    return 0;
}