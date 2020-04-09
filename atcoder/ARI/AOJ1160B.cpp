#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using Field = vector<vector<int>>;
using Graph = vector<vector<int>>;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

vector<int> dx = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};

void rec(int i, int j, Field &c, vector<vector<bool>> &done, int w, int h) {
    if (i < 0 || h <= i || j < 0 || w <= j) return;
    if (done.at(i).at(j)) return;
    if (c.at(i).at(j) == 0) return; 

    done.at(i).at(j) = true;
    c.at(i).at(j) = 1;

    REP(x, 8) {
        rec(i + dx.at(x), j + dy.at(x), c, done, w, h);
    }

    return;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int w, h; cin >> w >> h;
    Field c(h, vector<int>(w));
    REP(i, h) {
        REP(j, w) {
            int x; cin >> x;
            c.at(i).at(j) = x;
        }
    }

    vector<vector<bool>> done(h, vector<bool>(w, false));

    int ans = 0;

    REP(i, h) {
        REP(j, w) {
            if (c.at(i).at(j) == 0) continue;
            if (done.at(i).at(j)) continue;

            ans++;
            rec(i, j, c, done, w, h);


        }
    }

    cout << ans << endl;
    

    return 0;
}