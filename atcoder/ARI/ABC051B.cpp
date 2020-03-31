#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int k, s;
    cin >> k >> s;

    int cnt = 0;
    
    for (int x = 0; x < k + 1; x++) {
        for (int y = 0; y < k + 1; y++) {
            int z = s - x - y;
            if (0 <= z && z <= k) cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}