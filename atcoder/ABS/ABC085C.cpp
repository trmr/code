#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, y; cin >> n >> y;

    REP(i, n + 1) {
        REP(j, n + 1 - i) {
            int k = n - i - j;
            if (i * 10000 + j * 5000 + k * 1000 == y) {
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }

    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}