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

const int MAX = 100000;
const int INFTY = (1 << 30);

struct Edge {
    int t, w;
    Edge(){}
    Edge(int t, int w): t(t), w(w) {}
};

vector<Edge> G[MAX];
int n, d[MAX];

bool visited[MAX];
int cnt;

void bfs(int s) {
    for (int i = 0; i < n; i++) d[i] = INFTY;
    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    int u;
    while (!Q.empty()) {
        u = Q.front(); Q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            Edge e = G[u][i];
            if (d[e.t] == INFTY) {
                d[e.t] = d[u] + e.w;
                Q.push(e.t);
            }
        }
    }
}

void solve() {
    bfs(0);
    int maxv = 0;
    int tgt = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] == INFTY) continue;
        if (maxv < d[i]) {
            maxv = d[i];
            tgt = i;
        }
    }

    bfs(tgt);
    maxv = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] == INFTY) continue;
        maxv = max(maxv, d[i]);
    }

    cout << maxv << endl;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int s, t, w;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> s >> t >> w;

        G[s].push_back(Edge(t, w));
        G[t].push_back(Edge(s, w));
    }

    solve();

    return 0;
}