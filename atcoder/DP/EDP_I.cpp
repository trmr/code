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
vector<vector<double>> dp(3010, vector<double>(3010, 0));
vector<double> p;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    p.resize(N, 0);

    REP(i, N) cin >> p.at(i);

    dp.at(0).at(0) = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp.at(i + 1).at(j + 1) += dp.at(i).at(j) * p.at(i);
            dp.at(i + 1).at(j) += dp.at(i).at(j) * (1 - p.at(i)); 
        }
    }

    double ans = 0;

    for (int i = 0; i < (N + 1)/2; i++) {
        ans += dp.at(N).at(i);
    }

    cout << setprecision(10) << (double)1 - ans << endl;
    
    return 0;
}