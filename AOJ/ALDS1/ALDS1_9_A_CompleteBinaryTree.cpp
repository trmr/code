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

ll n;
vector<ll> H;

ll getLeftkey(vector<ll> H, ll idx) {
    if (idx * 2 < H.size()) {
        return H[idx * 2];
    } else {
        return INF;
    }
}

ll getrightkey(vector<ll> H, ll idx) {
    if (idx * 2 + 1 < H.size()) {
        return H[idx * 2 + 1];
    } else {
        return INF;
    }
}

ll getparentkey(vector<ll> H, ll idx) {
    if (idx != 1) {
        return H[ idx / 2];
    } else {
        return INF;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    H.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> H[i];

    for (int i = 1; i <= n; i++) {
        cout << "node " << i << ": key = " << H[i] << ", ";
        ll lk = getLeftkey(H, i);
        ll rk = getrightkey(H, i);
        ll pk = getparentkey(H, i);
        if (pk != INF) cout << "parent key = " << pk << ", ";
        if (lk != INF) cout << "left key = " << lk << ", ";
        if (rk != INF) cout << "right key = " << rk << ", ";
        cout << endl;
    }
    return 0;
}