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

    int h, w, n; cin >> h >> w >> n;

    vector<vector<char>> c(h, vector<char>(w));

    REP(i, h) {
        string line; cin >> line;
        REP(j, w) {
            c.at(i).at(j) = line.at(j);
        }
    }

    int sx, sy;
    REP(i, h) REP(j, w) if (c.at(i).at(j) == 'S') {sy = i; sx = j; break;}

    char goal = '1';
    int ans = 0;

    while ((goal - '0') <= n) {
        Field dp(h, vector<int>(w, INT32_MAX));

        int gx, gy;
        REP(i, h) REP(j, w) if (c.at(i).at(j) == goal) {gy = i; gx = j; break;}

        
        dp.at(sy).at(sx) = 0;
        pair<int, int> p = {sy, sx};

        queue<pair<int, int>> que;
        que.push(p);

        while (!que.empty()) {
            bool flag = false;
            pair<int, int> _p = que.front();
            que.pop();

            int y = _p.first;
            int x = _p.second;

            REP(i, 4) {
                int nx = x + dx.at(i); int ny = y + dy.at(i);
                if (ny < 0 || h <= ny || nx < 0 || w <= nx || c.at(ny).at(nx) == 'X') continue;
                if (dp.at(ny).at(nx) != INT32_MAX) continue;

                dp.at(ny).at(nx) = min(dp.at(ny).at(nx), dp.at(y).at(x) + 1);

                if (ny == gy && nx == gx) {
                    flag = true;
                    break;
                }
                
                que.push(make_pair(ny, nx));
            }

            if (flag) {
                ans += dp.at(gy).at(gx);
                goal++;
                sy = gy;
                sx = gx;
                break;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}