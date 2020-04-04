#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, x, y; cin >> n >> x >> y;
    x--; y--;

    vector<int> dist(n, 0);
    
    for (int src = 0; src < n - 1; src++) {
        for (int dst = src + 1; dst < n; dst++) {
            int d = min(dst - src, abs(x - src) + abs(dst - y) + 1);
            dist.at(d)++;
        }
    }

    for (int k = 1; k < n; k++) {
        cout << dist.at(k) << endl;
    }

    return 0;
}