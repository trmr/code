#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using Field = vector<vector<int>>;
using Graph = vector<vector<int>>;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int rec(int x, int y, int h, int w, vector<vector<char>> &c, vector<vector<bool>> &done) {
    if (x < 0 || h <= x || y < 0 || w <= y) return 0;
    if (c.at(x).at(y) == 'g') return 1;
    if (done.at(x).at(y)) return 0;
    if (c.at(x).at(y) == '#') return 0;

    done.at(x).at(y) = true;

    for (int i = 0; i < 4; i++) {
        if (rec(x + dx.at(i), y + dy.at(i), h, w, c, done)) {
            return 1;
        }
    }
    return 0;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int h, w; cin >> h >> w;
    vector<vector<char>> c(h,vector<char>(w));
    vector<vector<bool>> done(h,vector<bool>(w, false));

    for (int i = 0; i < h; i++) {
        string line; cin >> line;
        for (int j = 0; j < w; j++) {
            c.at(i).at(j) = line.at(j);

        }
    }
    int sx, sy;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (c.at(i).at(j) == 's') {
                sx = i; sy = j;
            }
        }
    }

    if (rec(sx, sy, h, w, c, done)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
}