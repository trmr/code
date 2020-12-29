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

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

int n;

void koch(double s, double t, double u, double v, int round) {
    if (round == n)  return;
    double x1 = (2 * s + u) / 3;
    double y1 = (2 * t + v) / 3;
    double x2 = (s + 2 * u) / 3;
    double y2 = (t + 2 * v) / 3;
    double x3 = x1 + (x2 - x1) * cos(60 * M_PI / 180) - (y2 - y1) * sin(60 * M_PI / 180);
    double y3 = y1 + (x2 - x1) * sin(60 * M_PI / 180) + (y2 - y1) * cos(60 * M_PI / 180);

    koch(s, t, x1, y1, round + 1);

    cout << fixed << x1 << " " << y1 << endl;

    koch(x1, y1, x3, y3, round + 1);

    cout << fixed << x3 << " " << y3 << endl;

    koch(x3, y3, x2, y2, round + 1);

    cout << x2 << " " << y2 << endl;

    koch(x2, y2, u, v, round + 1);

    return;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;

    cout << fixed << 0.0 << " " << 0.0 << endl;
    koch(0, 0, 100, 0, 0);
    cout << fixed << 100.0 << " " << 0.0 << endl;

    return 0;
}