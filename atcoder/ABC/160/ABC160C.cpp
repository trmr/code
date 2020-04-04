#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int k, n; cin >> k >> n;
    vector<int> A(n);
    REP(i, n) cin >> A.at(i);

    int max_d = 0;
    int max_i = 0;

    for (int i = 0; i < n; i++) {
        int d;
        if (i == n - 1) {
            d = A.at(0) + k - A.at(i);
        } else {
            d = A.at(i + 1) - A.at(i);
        }
        max_d = max(d, max_d);
    }

    cout << k - max_d << endl;

    return 0;
}