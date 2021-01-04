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

int n, m, q;
vector<vector<int>> T;
vector<bool> d;
vector<int> color;

#define NIL -1

void checkFriend(int a, int b) {
    color[a] = b;
    for (int i = 0; i < T[a].size(); i++) {
        int n = T[a][i];
        if (color[n] == -1) {
            checkFriend(n, b);
        }
    }

    return;
}

void assignColor() {
    int id = 1;
    for (int i = 0; i < n; i++) color[i] = NIL;
    for (int u = 0; u < n; u++) {
        if (color[u] == NIL) checkFriend(u, id++);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    T.assign(n, vector<int>());
    color.assign(n, NIL);

    REP(i, m) {
        int a, b; cin >> a >> b;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    
    assignColor();

    cin >> q;
    REP(i, q) {
        int s, t;
        cin >> s >> t;

        if (color[s] == color[t]) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }



    return 0;
}