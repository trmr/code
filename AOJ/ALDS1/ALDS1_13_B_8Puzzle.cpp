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

#define N 3
#define N2 9

struct Puzzle {
    int f[N2];
    int space;
    string path;

    bool operator < ( const Puzzle &p ) const {
        for (int i = 0; i < N2; i++) {
            if ( f[i] == p.f[i] ) continue;
            return f[i] > p.f[i];
        }
        return false;
    }
};

static const int dx[4] = {1, 0, -1, 0};
static const int dy[4] = {0, 1, 0, -1};
static const char dir[4] = {'r', 'u', 'l', 'd'};

bool isTarget(Puzzle p) {
    for (int i = 0; i < N2; i++) {
        if (p.f[i] != (i + 1)) return false;
    }
    return true;
}

string bfs(Puzzle s) {
    queue<Puzzle> Q;
    map<Puzzle, bool> V;
    Puzzle u, v;
    s.path = "";
    Q.push(s);
    V[s] = true;

    while (!Q.empty()) {
        u = Q.front(); Q.pop();
        if ( isTarget(u) ) return u.path;
        int sx = u.space % N;
        int sy = u.space / N;
        for (int r = 0; r < 4; r++) {
            int tx = sx + dx[r];
            int ty = sy + dy[r];
            if (tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
            v = u;
            swap(v.f[u.space], v.f[ty * N + tx]);
            v.space = ty * N + tx;
            if (V[v] == false) {
                V[v] = true;
                v.path += dir[r];
                Q.push(v);
            }
        }
    }
    return "unsolvable";
}

int main() {
    Puzzle in;

    for (int i = 0; i < N2; i++) {
        cin >> in.f[i];
        if ( in.f[i] == 0) {
            in.f[i] = N2;
            in.space = i;
        }
    }
    string ans = bfs(in);
    cout << ans.size() << endl;

    return 0;
}
