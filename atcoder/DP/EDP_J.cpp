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
vector<int> a;
vector<vector<vector<double>>> dp(310, vector<vector<double>>(310, vector<double>(310, -1)));

double rec(int i, int j, int k) {
    if (dp.at(i).at(j).at(k) >= 0) return dp.at(i).at(j).at(k);
    if (i == 0 && j == 0 && k == 0) return 0;

    double res = 0.0;

    if (i > 0) res += rec(i - 1, j, k) * i;
    if (j > 0) res += rec(i, j - 1, k) * j;
    if (k > 0) res += rec(i, j + 1, k - 1) * k;
    res += N;
    res *= 1.0/(i + j + k);

    return dp.at(i).at(j).at(k) = res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    a.resize(N);
    REP(i, N) cin >> a.at(i);

    int i = 0, j = 0, k = 0;

    for (auto na : a) {
        if (na == 1) i++;
        else if (na == 2) j++;
        else if (na == 3) k++;
    }

    dp.at(i).at(j).at(k) == 0;

    double ans = 0.0;

    ans = rec(i, j, k);

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}