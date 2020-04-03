#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int d, g; cin >> d >> g;
    vector<int> p(d);
    vector<int> c(d);
    REP(i, d) {
        cin >> p.at(i) >> c.at(i);
    }

    int min_solved = 1000000000;

    for (int i = 0; i < 1 << d; i++) {
        bitset<10> bit(i);

        int current_g = 0;
        int solved = 0;

        for (int x = 0; x < d; x++) {
            if (bit.test(x)) {
                current_g += (100 * (x + 1) * p.at(x) + c.at(x));
                solved += p.at(x); 
            }
        }

        if (current_g >= g) {
            min_solved = min(min_solved, solved);
            continue;
        }

        bool flag = false;

        for (int x = d - 1; x >= 0; x--) {
            if (!bit.test(x)) {
                for (int y = 0; y < p.at(x); y++) {
                    current_g += 100 * (x + 1);
                    solved++;

                    if (current_g >= g) {
                        min_solved = min(min_solved, solved);
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) break;
        }
    }

    cout << min_solved << endl;
    
    return 0;
}