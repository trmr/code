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

Point project(Segment s, Point p) {
    Vector base = s.v2 - s.v1;
    double r = dot(p - s.v1, base) / base.norm();
    return s.v1 + base * r;
}

double getDistance(Point a, Point b) {
    return (a - b).abs();
}

double getDistanceLP(Line l, Point p) {
    return abs(cross(l.v2 - l.v1, p - l.v1) / (l.v2 - l.v1).abs());
}

double getDistanceSP(Segment s, Point p) {
    if ( dot(s.v2 - s.v1, p - s.v1) < 0.0) return (p - s.v1).abs();
    if ( dot(s.v1 - s.v2, p - s.v2) < 0.0) return (p - s.v2).abs();
    return getDistanceLP(s, p);
}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw(Point p0, Point p1, Point p2) {
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if ( cross(a, b) > 0.00000000001) return COUNTER_CLOCKWISE;
    if ( cross(a, b) < -0.00000000001) return CLOCKWISE;
    if ( dot(a, b) < -0.000000000001) return ONLINE_BACK;
    if ( (a.norm() < b.norm())) return ONLINE_FRONT;

    return ON_SEGMENT;
}

bool intersect(Point p1, Point p2, Point p3, Point p4) {
    return ( 
        ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
        ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(Segment s1, Segment s2) {
    return intersect(s1.v1, s1.v2, s2.v1, s2.v2);
}

bool intersect(Circle c, Segment s) {
    return (c.r - getDistanceSP(s, c.c)) >= 0.0;
}

double getDistance(Segment s1, Segment s2) {
    if ( intersect(s1, s2)) return 0.0;
    return min(min(getDistanceSP(s1, s2.v1), getDistanceSP(s1, s2.v2)), min(getDistanceSP(s2, s1.v1), getDistanceSP(s2, s1.v2)));
}
Point getCrossPoint(Segment s1, Segment s2) {
    Vector base = s2.v2 - s2.v1;
    double d1 = abs(cross(base, s1.v1 - s2.v1));
    double d2 = abs(cross(base, s1.v2 - s2.v1));
    double t = d1 / (d1 + d2);
    return s1.v1 + (s1.v2 - s1.v1) * t;
}

pair<Point, Point> getCrossPoint(Circle c, Line l) {
    //assert(intersect(c, l));
    Vector pr = project(l, c.c);
    Vector e = (l.v2 - l.v1) / (l.v2 - l.v1).abs();
    double base = sqrt(c.r * c.r - (pr - c.c).norm());
    return make_pair(pr + e * base, pr - e * base);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    double cx, cy, r;
    cin >> cx >> cy >> r;
    Circle c(Vector(cx, cy), r);
    int q; cin >> q;

    REP(i, q) {
        double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        Line l(Point(x1, y1), Point(x2, y2));
        pair<Point, Point> ans = getCrossPoint(c, l);
        double ansx1, ansy1, ansx2, ansy2;
        if (ans.first.x < ans.second.x){ ansx1 = ans.first.x; ansy1 = ans.first.y; ansx2 = ans.second.x; ansy2 = ans.second.y;}
        else if (ans.first.x > ans.second.x) {ansx1 = ans.second.x; ansy1 = ans.second.y; ansx2 = ans.first.x; ansy2 = ans.first.y;}
        else if (ans.first.y < ans.second.y) {ansx1 = ans.first.x; ansy1 = ans.first.y; ansx2 = ans.second.x; ansy2 = ans.second.y;}
        else {ansx1 = ans.second.x; ansy1 = ans.second.y; ansx2 = ans.first.x; ansy2 = ans.first.y;}
        cout << fixed << setprecision(10) << ansx1 << " " << ansy1 << " " << ansx2 << " " << ansy2 << endl;
    }



    return 0;
}