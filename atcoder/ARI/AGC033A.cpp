#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using Field = vector<vector<int>>;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int h, w; cin >> h >> w;
    vector<vector<char>> A(h, vector<char>(w));

    REP(i, h) {
        string line; cin >> line;
        REP(j, w) {
            A.at(i).at(j) = line.at(j);
        }
    }

    queue<P> que;
    Field dp(h, vector<int>(w, INT32_MAX));

    REP(i, h) REP (j, w) {
        if (A.at(i).at(j) == '#') {
            int y = i, x = j;
            dp.at(y).at(j) = 0;
            P _p = make_pair(i, j);
            que.push(_p);
        }
    }
    


    while (!que.empty()) {
        P p = que.front();
        que.pop();

        int y = p.first, x = p.second;

        REP (i, 4) {
            int ny = y + dy.at(i), nx = x + dx.at(i);
            if (ny < 0 || h <= ny || nx < 0 || w <= nx || A.at(ny).at(nx) == '#') continue;

            dp.at(ny).at(nx) = min(dp.at(ny).at(nx), dp.at(y).at(x) + 1);
            A.at(ny).at(nx) = '#';

            que.push(make_pair(ny, nx));

        }
    }

    int ans = 0;

    REP(i, h) {
        ans = max(ans, *max_element(dp.at(i).begin(), dp.at(i).end()));
    }

    cout << ans << endl;
    
    return 0;
}