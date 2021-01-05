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

vector<int> G[MAX];
int N;
bool visited[MAX];
int prenum[MAX], parent[MAX], lowest[MAX], timer;

void dfs(int current, int prev) {
    prenum[current] = lowest[current] = timer;
    timer++;

    visited[current] = true;

    int next;

    for (int i = 0; i < G[current].size(); i++) {
        next = G[current][i];
        if (!visited[next]) {
            parent[next] = current;

            dfs(next, current);
            lowest[current] = min(lowest[current], lowest[next]);
        } else if ( next != prev) {
            lowest[current] = min( lowest[current], prenum[next]);
        }
    }
}

void art_points() {
    for (int i = 0; i < N; i++) visited[i] = false;
    timer = 1;
    dfs(0, -1);

    set<int> ap;
    int np = 0;
    for (int i = 1; i < N; i++) {
        int p = parent[i];
        if (p == 0) np++;
        else if (prenum[p] <= lowest[i]) ap.insert(p);
    }
    if (np > 1) ap.insert(0);
    for (auto it = ap.begin(); it != ap.end(); it++) {
        cout << *it << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int m;
    cin >> N >> m;

    for (int i = 0; i < m; i++) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    art_points();



    return 0;
}