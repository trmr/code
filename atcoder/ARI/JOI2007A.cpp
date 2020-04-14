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

VI coin = {500, 100, 50, 10, 5, 1};


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;

    int change = 1000 - n;

    int cnt = 0;

    REP(i, coin.size()) {
        while (change >= coin.at(i)) {
            change -= coin.at(i);
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}