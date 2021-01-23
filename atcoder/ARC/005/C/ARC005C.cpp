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

const int dh[4] = {1, 0, -1, 0};
const int dw[4] = {0, 1, 0, -1};

int H, W;
int sh, sw, gh, gw;
vector<vector<char>> M;

struct Node {
    int h, w, c;
    Node(int height, int weight, int count) {
        h = height, w = weight, c = count;
    }
};

bool bfs(vector<vector<char>> tM) {
    queue<Node> q;
    q.push(Node(sh, sw, 0));
    vector<vector<int>> gone(H, vector<int>(W, (1 << 20)));
    gone[sh][sw] = 0;

    while (!q.empty()) {
        auto p = q.front(); q.pop();
        REP(i, 4) {
            int ch = p.h + dh[i];
            int cw = p.w + dw[i];
            int cc = p.c;

            if (ch < 0 || cw < 0 || H <= ch || W <= cw) continue;
            if (gone[ch][cw] <= cc) continue;
            if (tM[ch][cw] == '#') {
                if (cc >= 2) continue;
                cc++;
            }

            if (tM[ch][cw] == 'g') return true;
            gone[ch][cw] = cc;
            q.push(Node(ch, cw, cc));
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> H >> W;
    M.assign(H, vector<char>(W));

    REP(i, H) REP(j, W) {
        cin >> M[i][j];
        if (M[i][j] == 's') sh = i, sw = j;
        if (M[i][j] == 'g') gh = i, gw = j;
    }

    bool flag = false;

    if (bfs(M)) flag = true;

    cout << (flag? "YES" : "NO") << endl;


    return 0;
}