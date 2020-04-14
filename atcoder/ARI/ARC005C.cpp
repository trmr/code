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

VI dx = {-1, 0, 1, 0};
VI dy = {0, 1, 0, -1};


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int h, w; cin >> h >> w;
    vector<VC> c(h, VC(w));

    REP(i, h) {
        string line; cin >> line;
        REP(j, w) {
            c.at(i).at(j) = line.at(j);
        }
    }

    Field dp(h, VI(w, INT32_MAX));

    int sy, sx, gy, gx;
    REP(i, h) REP(j , w) {
        if (c.at(i).at(j) == 's') {
            sy = i; sx = j;
        }else if (c.at(i).at(j) == 'g') {
            gy = i; gx = j;
        }
    }

    PI _p = make_pair(sy, sx);
    queue<PI> que;
    que.push(_p);
    dp.at(sy).at(sx) = 0;

    bool flag = false;

    while(!que.empty()) {
        PI p = que.front();
        que.pop();

        int y = p.first, x = p.second;

        REP(i, 4) {
            int ny = y + dy.at(i), nx = x + dx.at(i);
            if (ny < 0 || h <= ny || nx < 0 || w <= nx) continue;
            if (dp.at(ny).at(nx) <= dp.at(y).at(x)) continue;
            int fence = 0;
            if (c.at(ny).at(nx) == '#') {
                fence = 1;
                if (dp.at(y).at(x) + fence > 2) continue;
            }

            dp.at(ny).at(nx) = min(dp.at(ny).at(nx), dp.at(y).at(x) + fence);

            if (ny == gy && nx == gx) {
                if (dp.at(gy).at(gx) <= 2) {
                    flag = true;
                    break;
                }
            }

            que.push(make_pair(ny, nx));
        }

        if (flag) break;
    }

    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}