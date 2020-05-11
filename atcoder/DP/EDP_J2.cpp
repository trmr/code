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
vector<double> a;
vector<vector<vector<double>>> dp(310, vector<vector<double>>(310, vector<double>(310)));

double rec(int i, int j, int k) {
    if (dp[i][j][k] != 0) return dp[i][j][k];
    if (i == 0 && j == 0 && k == 0) return 0;

    double res = 0.0;

    if (i >= 1) res += rec(i - 1, j, k) * i;
    if (j >= 1) res += rec(i + 1, j - 1, k) * j;
    if (k >= 1) res += rec(i, j + 1, k - 1) * k;
    res += N;
    res /= (i + j + k);
    return dp[i][j][k] = res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    a.resize(N);

    REP(i, N) cin >> a[i];

    int one = 0;
    int two = 0;
    int three = 0;


    for (auto x:a) {
        if (x == 1) one++;
        else if (x == 2) two++;
        else if (x == 3) three++;
    }

    double ans = 0.0;

    ans = rec(one, two, three);
    
    cout << setprecision(10) << ans << endl;

    return 0;
}