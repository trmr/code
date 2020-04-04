#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<int> x(m);
    vector<int> y(m);
    vector<vector<bool>> mat(n, vector<bool>(n));

    REP(i, m) {
        cin >> x.at(i) >> y.at(i);
        x.at(i)--; y.at(i)--;
        mat.at(x.at(i)).at(y.at(i)) = true;
        mat.at(y.at(i)).at(x.at(i)) = true;
    }

    int ans = 0;

    for (int i = 0; i < 1 << n; i++) {
        bitset<12> bit(i);
        if (bit.count() <= ans) continue;

        bool flag = true;

        for (int x = 1; x < n; x++) {
            for (int y = 0; y < x; y++) {

                if (bit.test(x) && bit.test(y)) {
                    if (!mat.at(x).at(y) || !mat.at(y).at(x)) {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag) break;
        }
        if (flag) ans = max(ans, (int)bit.count());
    }

    cout << ans << endl;
      
    return 0;
}