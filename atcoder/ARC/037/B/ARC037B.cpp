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

struct Node {
    int id;
    vector<int> child;
    bool done = false;
};

vector<Node> T;

int ans = 0;

bool bfs(int id, int par) {
    if (T[id].done) return false;
    T[id].done = true;
    for (int i = 0; i < T[id].child.size(); i++) {
        if (T[id].child[i] == par) continue;
        if (!bfs(T[id].child[i], T[id].id)) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    T.resize(N);

    REP(i, M) {
        int id, ch;
        cin >> id >> ch;
        id--; ch--;
        T[id].child.push_back(ch);
        T[ch].child.push_back(id);
        T[id].id = id;
        T[ch].id = ch;
    }

    for (int i = 0; i < N; i++) {
        if (bfs(i, -1)) ans++;
    }

    cout << ans << endl;

    return 0;
}