#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cinttypes>
#include <cstdint>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <chrono>
#include <forward_list>
#include <initializer_list>
#include <random>
#include <regex>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using ll = long long;
using Field = vector<vector<ll>>;
using Graph = vector<vector<ll>>;
using VI = vector<int>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VC = vector<char>;
using PI = pair<int, int>;

#define FOR(i, s, n) for (int i = s; i < (n); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const long long INF = 1LL<<60;
const int MOD = 1000000007;
const double EPS = 0.00000000001;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

vector<vector<char>> M;
vector<vector<bool>> gone;
int H, W;

static const int dh[4] = {0, 1, 0, -1};
static const int dw[4] = {1, 0, -1, 0};


struct Point {
    int h, w, c;
    Point(int height, int weight, int count) {
        h = height, w = weight, c = count;
    }
};

int bfs(int sh, int sw) {
    queue<Point> q;
    q.push(Point(sh, sw, 0));

    while (!q.empty()) {
        auto p = q.front(); q.pop();
        if (p.h < 0 || p.w < 0 || H <= p.h || W <= p.w) continue;
        if (M[p.h][p.w] == '#') continue;
        if (gone[p.h][p.w]) continue;
        if (p.h == H - 1 && p.w == W - 1) return p.c;

        gone[p.h][p.w] = true;

        REP(i, 4) {
            q.push(Point(p.h + dh[i], p.w + dw[i], p.c + 1));
        }
    }
    return -1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> H >> W;
    M.assign(H, vector<char>(W));
    gone.assign(H, vector<bool>(W));
    REP(i, H) REP(j, W) {
        cin >> M[i][j];
    }

    int ans = bfs(0, 0);

    if (ans == -1) cout << -1 << endl;

    int wall = 0;
    REP(i, H) REP(j, W) {
        if (M[i][j] == '#') wall++;
    }

    ans = H * W - ans - wall - 1;

    cout << ans << endl;

    return 0;
}