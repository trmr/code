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

struct Node {
    int id;
    int parent;
    int depth;
    string type;
    vector<int> child;
};

void checkNode(vector<Node> &V, int cur, int prev, int d) {

    V[cur].depth = d;
    V[cur].parent = prev;
    if (V[cur].parent == -1) {
        V[cur].type = "root";
    } else if (V[cur].child.size() == 0) {
        V[cur].type = "leaf";
    } else {
        V[cur].type = "internal node";
    }

    for (int c :V[cur].child) {
        checkNode(V, c, cur, d + 1);
    }

    return;

}

int n;
vector<Node> V;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    V.resize(n);
    vector<bool> root(n, true);
    REP(i, n) {
        Node a;
        cin >> a.id;
        int t; cin >> t;
        REP(i, t) {
            int b; cin >> b;
            a.child.push_back(b);
            root[b] = false;
        }
        V[a.id] = a;
    }

    int r = 0;

    REP(i, n) {
        if (root[i]) {
            r = i;
            break;
        }
    }

    V[r].type = "root";
    V[r].parent = -1;

    checkNode(V, r, -1, 0);

    for (Node a : V) {
        cout << "node " << a.id << ": parent = " << a.parent << ", depth = " << a.depth << ", " << a.type << ", [";
        for (int i = 0; i < a.child.size(); i++) {
            if (i != 0) cout << ", ";
            cout << a.child[i];
        }
        cout << "]" << endl;
    }

    return 0;
}