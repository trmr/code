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



    int R, C; cin >> R >> C;
    int sx, sy; cin >> sx >> sy;
    int gx, gy; cin >> gx >> gy;
    sx--; sy--; gx--; gy--;

    Field c(R, vector<int>(C));
    queue<pair<int, int>> que;


    REP(i, R) {
        string line; cin >> line;
        REP(j, C) {
            c.at(i).at(j) = line.at(j);
        }
    }

    Field dp(R, vector<int>(C, INT32_MAX));

    
    que.push(make_pair(sx, sy));
    dp.at(sx).at(sy) = 0;

    while (!que.empty()) {
        pair<int, int> p = que.front();
        int x = p.first;
        int y = p.second;
        que.pop();

        if (x == gx && y == gy) {
            break;
        }

        REP(i, 4) {
            int nx = x + dx.at(i); int ny = y + dy.at(i);
            if (nx < 0 || C <= nx || ny < 0 || R <= ny) continue;
            if (c.at(nx).at(ny) == '#') continue;
            if (dp.at(nx).at(ny) == INT32_MAX) {
                que.push(make_pair(nx, ny));
                dp.at(nx).at(ny) = dp.at(x).at(y) + 1;
            }

        }
    }

    cout << dp.at(gx).at(gy) << endl;
    
    return 0;
}