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

const int MAX = 10000;
const int INFTY = (1 << 29);

struct DisjointSet {
    vector<int> rank, p;

    DisjointSet() {}
    DisjointSet(int size) {
        rank.resize(size, 0);
        p.resize(size, 0);
        for (int i=0; i < size; i++) makeSet(i);
    }

    void makeSet(int x) {
        p[x] = x;
        rank[x] = 0;
    }

    bool same(int x, int y) {
        return findSet(x) == findSet(y);
    }

    void unite(int x, int y) {
        link(findSet(x), findSet(y));
    }

    void link(int x, int y) {
        if ( rank[x] > rank[y]) {
            p[y] = x;
        } else {
            p[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }

    int findSet(int x) {
        if (x != p[x]) {
            p[x] = findSet(p[x]);
        }
        return p[x];
    }
};

struct Edge {
    int source, target, cost;
    Edge(int source = 0, int target = 0, int cost = 0):
    source(source), target(target), cost(cost) {}
    bool operator < (const Edge &e) const {
        return cost < e.cost;
    }
};

int kruskal(int N, vector<Edge> edges) {
    int totalcost = 0;
    sort(edges.begin(), edges.end());
    DisjointSet ds = DisjointSet(N + 1);

    for (int i = 0; i < N; i++) ds.makeSet(i);

    int source, target;
    for (int i = 0; i < edges.size(); i++) {
        Edge e = edges[i];
        if (!ds.same(e.source, e.target)){
            totalcost += e.cost;
            ds.unite(e.source, e.target);
        }
    }
    return totalcost;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M, cost;
    int source, target;

    cin >> N >> M;

    vector<Edge> edges;
    for (int i = 0; i < M; i++) {
        cin >> source >> target >> cost;
        edges.push_back(Edge(source, target, cost));
    }

    cout << kruskal(N, edges) << endl;



    return 0;
}