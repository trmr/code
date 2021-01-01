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
    int parent = -1;
    int left = -1;
    int right = -1;
    int sibling = -1;
    int degree = 0;
    int depth = -1;
    int height = -1;
    string type;
};

vector<Node> T;

int setNode(int cur, int par, int dep) {
    T[cur].parent = par;
    if (par != -1 && T[par].left == cur) {
        T[cur].sibling = T[par].right;
    } else if (par != -1) {
        T[cur].sibling = T[par].left;
    }
    T[cur].depth = dep;
    if (T[cur].left != -1) {
        T[cur].degree++;
        int h = setNode(T[cur].left, cur, dep + 1);
        chmax(T[cur].height, h + 1);
    }
    if (T[cur].right != -1) {
        T[cur].degree++;
        int h = setNode(T[cur].right, cur, dep + 1);
        chmax(T[cur].height, h + 1);
    }
    if (T[cur].left == -1 && T[cur].right == -1) {
        T[cur].height = 0;
        if (par == -1) T[cur].type = "root";
        else T[cur].type = "leaf";
        return 0;
    }

    if (T[cur].parent == -1) {
        T[cur].type = "root";
    } else {
        T[cur].type = "internal node";
    }

    return T[cur].height;
}
    

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    T.resize(n);
    vector<bool> R(n, true);
    REP(i, n) {
        int a, l, r;
        cin >> a >> l >> r;
        T[a].left = l; T[a].right = r;
        if (l != -1) R[l] = false;
        if (r != -1) R[r] = false;
    }

    int rootid;

    rootid = find(ALL(R), true) - R.begin();

    setNode(rootid, -1, 0);

    REP(i, n) {
        cout << "node " << i
        << ": parent = " << T[i].parent
        << ", sibling = " << T[i].sibling
        << ", degree = " << T[i].degree
        << ", depth = " << T[i].depth
        << ", height = " << T[i].height
        << ", " << T[i].type << endl;
    }

    return 0;
}