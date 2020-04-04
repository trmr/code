#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int x, y, a, b, c; cin >> x >> y >> a >> b >> c;
    vector<int> p(a);
    vector<int> q(b);
    vector<int> r(c);

    REP(i, a) cin >> p.at(i);
    REP(i, b) cin >> q.at(i);
    REP(i, c) cin >> r.at(i);

    vector<pair<int, string>> v(a + b + c);

    REP(i, a) {
        v.push_back(make_pair(p.at(i), "red"));
    }
    REP(i, b) {
        v.push_back(make_pair(q.at(i), "green"));
    }
    REP(i, c) {
        v.push_back(make_pair(r.at(i), "none"));
    }

    sort(v.begin(), v.end());

    int ans = 0;

    for (int i = 0; i < a + b + c; i++) {
        string color = v.at(i).second;
        int point = v.at(i).first;

        if (color == "red") {
            if ((a + c == x) || (b + c == y && a == x) || (a + b + c == x + y)) {
                x--;
                ans += point;
            }
            a--;
            
        } else if (color == "green") {
            if ((b + c == y) || (a + c == x && b == y) || (a + b + c == x + y)) {
                y--;
                ans += point;
            } 
            b--;
        } else if (color == "none") {
            if ((a + c == x) || (b + c == x) || (a + b + c == x + y)) {
                if (a < x) {
                    x--;
                } else if (y) {
                    y--;
                }
                ans += point;
            }
            c--;
        }
    }

    cout << ans << endl;


    return 0;
}