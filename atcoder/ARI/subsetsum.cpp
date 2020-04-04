#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

bool rec(int i, int x, vector<int> &a, vector<vector<int>> &dp) {
    if (i == 0) {
        if (i == 0) {
            return true;
        } else return false;
    }

    if (dp.at(i).at(x) != -1) return dp.at(i).at(x);

    if (rec(i - 1, x, a, dp)) return dp.at(i).at(x) = true;

    if (rec(i - 1, x - a[i], a, dp)) return dp.at(i).at(x) = true;

    return dp.at(i).at(x) = false;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a(n);
    REP(i, n) {cin >> a.at(i);}
    int x; cin >> x;

    const int MAX = 1000000;

    vector<vector<int>> dp(n + 1, vector<int>(MAX + 1, -1));

    if (rec(n, x, a, dp)) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}