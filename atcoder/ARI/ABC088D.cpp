#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using Field = vector<vector<int>>;
using Graph = vector<vector<int>>;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int h, w; cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w));

    REP(i, h) {
        string line; cin >> line;
        REP(j, w) {
            s.at(i).at(j) = line.at(j);
        }
    }

    Field dp(h, vector<int>(w, INT32_MAX));


    int sy = 0, sx = 0;
    int gy = h - 1, gx = w - 1;

    pair<int, int> sp = {sy, sx};
    queue<pair<int, int>> que;
    que.push(sp);
    dp.at(sy).at(sx) = 0;

    bool flag = false;

    while (!que.empty()) {
        pair<int, int> p = que.front();
        que.pop();

        int y = p.first, x = p.second;

        REP(i, 4) {
            int ny = y + dy.at(i), nx = x + dx.at(i);
            if (ny < 0 || h <= ny || nx < 0 || w <= nx || s.at(ny).at(nx) == '#') continue;
            if (dp.at(ny).at(nx) != INT32_MAX) continue;

            dp.at(ny).at(nx) = min(dp.at(ny).at(nx), dp.at(y).at(x) + 1);

            if (ny == gy && nx == gx) {
                flag = true;
                break;
            }
            que.push(make_pair(ny, nx));
        }
        if (flag) break;
    }

    if (flag) {
        int m = 0;
        REP(i, h) REP(j, w) if (s.at(i).at(j) == '#') m++;
        int ans = h * w - m - dp.at(gy).at(gx) - 1;
        cout << ans << endl;
    } else cout << -1 << endl;

    return 0;
}