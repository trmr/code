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

const int mod = 1000000007;

struct Point {
    int x, w;
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<Point> p(n);
    REP(i, n) cin >> p.at(i).x >> p.at(i).w;

    sort(ALL(p), [](const Point lp, const Point rp) {return lp.x + lp.w < rp.x + rp.w;});

    int pt = p.at(0).x + p.at(0).w;
    int ans = 1;

    for (int i = 1; i < n; i++) {
        if (pt <= p.at(i).x - p.at(i).w) {
            ans++;
            pt = p.at(i).x + p.at(i).w;
        }
    }

    cout << ans << endl;

    return 0;
}