#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> A(n);
    for (auto &x:A) cin >> x;

    int ans = 0;
    bool flag = false;

    while (1) {
        for (auto &x:A) {
            if (x % 2) {
                flag = true;
                break;
            }
            x /= 2;
        }
        if (flag) break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}