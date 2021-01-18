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

static const int dx[4] = {1, 0, -1, 0};
static const int dy[4] = {0, 1, 0, -1};

vector<vector<int>> m(10, vector<int>(10));

void bfs(int sh, int sw) {
    if (sh < 0 || sw < 0 || 10 <= sh || 10 <= sw) return;
    if (m[sh][sw] == 0) return;
    
    m[sh][sw] = 0;
    REP(i, 4) {
        bfs(sh + dy[i], sw + dx[i]);
    }

}

bool check() {
    REP(i, 10) REP(j, 10) {
        if (m[i][j] == 1) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    REP(i, 10) {
        string s;
        cin >> s;
        for (int j = 0; j < 10; j++) {
            if (s[j] == 'x') m[i][j] = 0;
            else m[i][j] = 1; 
        }
    }

    REP(i, 10) REP(j, 10) {
        if (m[i][j] == 1) continue;
        vector<vector<int>> tmpm = m;
        m[i][j] = 1;
        bfs(i, j);
        if (check()) {
            cout << "YES" << endl;
            return 0;
        }
        m = tmpm;
    }

    cout << "NO" << endl;

    return 0;
}