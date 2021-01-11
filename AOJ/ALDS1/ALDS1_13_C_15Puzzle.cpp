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

#define N 4
#define N2 16
#define LIMIT 100

static const int dx[4] = {1, 0, -1, 0};
static const int dy[4] = {0, 1, 0, -1};
static const char dir[4] = {'r', 'u', 'l', 'd'};
int MDT[N2][N2];

struct Puzzle { int f[N2], space, MD;};

Puzzle state;
int limit;
int path[LIMIT];

int getAllMD( Puzzle pz) {
    int sum = 0;
    for ( int i = 0; i < N2; i++) {
        if (pz.f[i] == N2) continue;
        sum += MDT[i][pz.f[i] - 1];
    }
    return sum;
}

bool isSolved() {
    for (int i = 0; i < N2; i++) if (state.f[i] != i + 1) return false;
    return true;
}

bool dfs(int depth, int prev) {
    if (state.MD == 0) return true;
    if (depth + state.MD > limit ) return false;

    int sx = state.space % N;
    int sy = state.space / N;
    Puzzle tmp;

    for (int i = 0; i < 4; i++) {
        int tx = sx + dx[i];
        int ty = sy + dy[i];
        if (tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
        if ( max(prev, i) - min(prev, i) == 2) continue;
        
        tmp = state;

        state.MD -= MDT[ty * N + tx][state.f[ty * N + tx] - 1];
        state.MD += MDT[sy * N + sx][state.f[ty * N + tx] - 1];
        swap(state.f[ty * N + tx], state.f[sy * N + sx]);
        state.space = ty * N + tx;
        if (dfs(depth + 1, i)) { path[depth] = i; return true;}
        state = tmp;
    }
    return false;
}

string iterative_deepening(Puzzle in) {
    in.MD = getAllMD(in);

    for ( limit = in.MD; limit <= LIMIT; limit++) {
        state = in;
        if ( dfs(0, -100)) {
            string ans = "";
            for (int i = 0; i < limit; i++) ans += dir[path[i]];
            return ans;
        }
    }
    return "unsolvable";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < N2; i++) {
        for (int j = 0; j < N2; j++) {
            MDT[i][j] = abs(i / N - j / N) + abs(i % N - j % N);
        }
    }

    Puzzle in;

    for (int i = 0; i < N2; i++) {
        cin >> in.f[i];
        if (in.f[i] == 0) {
            in.f[i] = N2;
            in.space = i;
        }
    }
    string ans = iterative_deepening(in);
    cout << ans.size() << endl;


    return 0;
}