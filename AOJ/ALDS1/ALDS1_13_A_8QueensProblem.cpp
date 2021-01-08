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

#define N 8
#define FREE -1
#define NOT_FREE 1

int row[N], col[N], dpos[2 * N - 1], dneg[2 * N - 1];

bool X[N][N];

void initialize() {
    for (int i = 0; i < N; i++) { row[i] = FREE, col[i] = FREE;}
    for (int i = 0; i < 2 * N - 1; i++ ) { dpos[i] = FREE; dneg[i] = FREE;}
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (X[i][j]) {
                if (row[i] != j) return;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ( (row[i] == j) ? "Q" : ".");
        }
        cout << endl;
    }
}

void recursive(int i) {
    if (i == N) {
        printBoard(); return;
    }

    for (int j = 0; j < N; j++) {
        if ((col[j] == NOT_FREE) || (dpos[i + j] == NOT_FREE) || dneg[i - j + N - 1] == NOT_FREE) continue;
        row[i] = j;
        col[j] = dpos[i + j] = dneg[i - j + N - 1] = NOT_FREE;
        recursive(i + 1);
        row[i] = col[j] = dpos[i + j] = dneg[i - j + N - 1] = FREE;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    initialize();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            X[i][j] = false;
        }
    }

    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int r, c; cin >> r >> c;
        X[r][c] = true;
    }

    recursive(0);



    return 0;
}