#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, y; cin >> n >> y;

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            int k = n - i - j;
            if (k < 0) break;
            int cand = 10000 * i + 5000 * j + 1000 * k;
            if (cand == y) {
                cout << i << " " << j << " " << k << endl;
                return 0;
            } else if (cand > y) break;
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}