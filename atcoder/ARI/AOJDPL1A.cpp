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

struct Coin{
    int value, count, total;
};


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    VI c(m);
    REP(i, m) cin >> c.at(i);

    vector<int> dp(50001, INT32_MAX);
    dp.at(0) = 0;

    REP(i, n+1) {
        REP(j, m) {
            if (i + c.at(j) <= n) {
                dp.at(i + c.at(j)) = min(dp.at(i + c.at(j)), dp.at(i) + 1);
            }
        }
    }

    cout << dp.at(n) << endl;

    return 0;
}