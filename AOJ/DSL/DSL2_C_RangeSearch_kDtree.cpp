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
    int location;
    int p, l, r;
    Node() {}
};

struct Point {
    int id, x, y;
    Point(){}
    Point(int id, int x, int y): id(id), x(x), y(y) {}
    bool operator < (const Point &p) const {
        return id < p.id;
    }
    void print() {
        cout << id << endl;
    }
};

static const int MAX = 1000000;
static const int NIL = -1;

int N;
Point P[MAX];
Node T[MAX];
int np;

bool lessX(const Point &p1, const Point &p2) {return p1.x < p2.x;}
bool lessY(const Point &p1, const Point &p2) {return p1.y < p2.y;}

int makeKDTree(int l, int r, int depth) {
    if ( !(l < r)) return NIL;
    int mid = (l + r ) / 2;
    int t = np++;
    if (depth % 2 == 0) {
        sort(P + l, P + r, lessX);
    }else {
        sort(P + l, P + r, lessY);
    }
    T[t].location = mid;
    T[t].l = makeKDTree(l, mid, depth + 1);
    T[t].r = makeKDTree(mid + 1, r, depth + 1);

    return t;
}

void find(int v, int sx, int tx, int sy, int ty, int depth, vector<Point> &ans) {
    int x = P[T[v].location].x;
    int y = P[T[v].location].y;

    if (sx <= x && x <= tx && sy <= y && y <= ty) {
        ans.push_back(P[T[v].location]);
    }

    if (depth % 2 == 0) {
        if (T[v].l != NIL) {
            if (sx <= x) find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
        }
        if (T[v].r != NIL) {
            if (x <= tx) find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
        }
    } else {
        if (T[v].l != NIL) {
            if (sy <= y) find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
        }
        if (T[v].r != NIL) {
            if (y <= ty) find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int x, y;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        P[i] = Point(i, x, y);
        T[i].l = T[i].r = T[i].p = NIL;
    }

    np = 0;

    int root = makeKDTree(0, N, 0);

    int q;
    cin >> q;
    int sx, tx, sy, ty;
    vector<Point> ans;
    for (int i = 0; i < q; i++) {
        cin >> sx >> tx >> sy >> ty;
        ans.clear();
        find(root, sx, tx, sy, ty, 0, ans);
        sort(ans.begin(), ans.end());
        for (int j = 0; j < ans.size(); j++) {
            ans[j].print();
        }
        cout << endl;
    }



    return 0;
}