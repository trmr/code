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

static const vector<int> dx = {1, 0, -1, 0};
static const vector<int> dy = {0, 1, 0, -1};

vector<vector<char>> c;
vector<vector<int>> done;
int H, W;

bool bfs(int curh, int curw) {
    if (curh < 0 || curw < 0 || H <= curh || W <= curw) return false;

    if (c[curh][curw] == 'g') return true;
    if (c[curh][curw] == '#') return false;
    if (done[curh][curw] == 1) return false;

    done[curh][curw] = 1;
    REP(i, 4) {
        if (bfs(curh + dy[i], curw + dx[i])) return true;
    }
    return false;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> H >> W;
    c.assign(H, vector<char>(W));
    int sy, sx;
    REP(i, H) {
        REP(j, W) {
            cin >> c[i][j];
            if (c[i][j] == 's') sy = i, sx = j;
        }
    }
    done.assign(H, vector<int>(W, 0));

    if (bfs(sy, sx)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}