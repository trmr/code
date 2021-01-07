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

#define EPS (1e - 10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

struct Vector {
    double x, y;

    Vector(double x = 0, double y = 0): x(x), y(y) {}

    Vector operator + (Vector v) {return Vector(x + v.x, y + v.y);}
    Vector operator - (Vector v) {return Vector(x - v.x, y - v.y);}
    Vector operator * (double a) {return Vector(a * x, a * y);}
    Vector operator / (double a) {return Vector(x / a, y / a);}

    double abs() { return sqrt(norm());}
    double norm() { return x * x + y * y;}

    bool operator < (const Vector &v) const {
        return x != v.x ? x < v.x : y < v.y;
    }

    bool operator == (const Vector &v) const {
        return fabs(x - v.x) < 0.00000000001 && fabs(y - v.y) < 0.00000000001;
    }

};

typedef Vector Point;

struct Segment {
    Vector v1, v2;

    Segment(Vector v1 = Vector(), Vector v2 = Vector()): v1(v1), v2(v2) {}
};

typedef Segment Line;

struct Circle {
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0): c(c) , r(r) {}
};

typedef vector<Point> Polygon;

double dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int q;
    int x1,x2,x3,x4, y1,y2,y3,y4;

    cin >> q;

    REP(i, q) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        Vector v1(x1, y1);
        Vector v2(x2, y2);
        Line L1(v1, v2);
        Line L2(Vector(x3,y3), Vector(x4,y4));

        if (dot(L1.v2 - L1.v1, L2.v2 - L2.v1) == 0.0) {
            cout << 1 << endl;
        } else if (cross(L1.v2 - L1.v1, L2.v2 - L2.v1) == 0.0) {
            cout << 2 << endl;
        } else {
            cout << 0 << endl;
        }

    }



    return 0;
}