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
const double EPS = 0.00000000001;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

#define MAX 1400

struct Rectangle {
    int height, pos;
};

int getLargestRectangle(int size, int buffer[]) {
    stack<Rectangle> S;
    int maxv = 0;
    buffer[size] = 0;

    for (int i = 0; i <= size; i++) {
        Rectangle rect;
        rect.height = buffer[i];
        rect.pos = i;
        if (S.empty()) {
            S.push(rect);
        } else {
            if (S.top().height < rect.height) {
                S.push(rect);
            } else if (S.top().height > rect.height) {
                int target = i;
                while (!S.empty() && S.top().height >= rect.height) {
                    Rectangle pre = S.top(); S.pop();
                    int area = pre.height * (i - pre.pos);
                    maxv = max(maxv, area);
                    target = pre.pos;
                }
                rect.pos = target;
                S.push(rect);
            }
        }
    }
    return maxv;

}

int H, W;
int buffer[MAX][MAX];
int T[MAX][MAX];

int getLargestRectangle() {
    for (int j = 0; j < W; j++) {
        for (int i = 0; i < H; i++) {
            if (buffer[i][j]) {
                T[i][j] = 0;
            } else {
                T[i][j] = (i > 0) ? T[i - 1][j] + 1 : 1;
            }
        }
    }

    int maxv = 0;
    for (int i = 0; i < H; i++) {
        maxv = max(maxv, getLargestRectangle(W, T[i]));
    }

    return maxv;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> buffer[i][j];
        }
    }

    cout << getLargestRectangle() << endl;

    return 0;
}