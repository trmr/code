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

vector<vector<int>> A;
vector<int> d, f;
int n;
int t;
queue<int> q;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> n;
    A.assign(n, vector<int>(n, 0));
    d.resize(n, -1);
    f.resize(n);

    REP(i, n) {
        int a, b;
        cin >> a >> b;
        a--;
        REP(j, b) {
            int c;
            cin >> c;
            c--;
            A[a][c] = 1;
        }
    }

    t = 0;
    d[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        REP(i, n) {
            if (A[v][i] == 1 && d[i] == -1) {
                d[i] = d[v] + 1; 
                q.push(i);
            }
        }

    }

    REP(i, n) cout << i + 1 << " " << d[i] << endl;

    return 0;
}