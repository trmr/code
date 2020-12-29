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

#define MAX 100000

int n, k;
ll T[MAX];

int check(ll P) {
    int i = 0;
    for (int j = 0; j < k; j++) {
        ll s = 0;
        while (s + T[i] <= P) {
            s += T[i];
            i++;
            if (i == n) return n;
        }
    }
    return i;
}

int solve() {
    ll left = 0;
    ll right = 100000 * 10000;
    ll mid;
    while (right - left > 1) {
        mid = (left + right) / 2;
        int v = check(mid);
        if (v >= n) right = mid;
        else left = mid;
    }
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    vector<ll> W;

    W.resize(n);

    REP(i, n) cin >> W[i];

    for (int p = 0; p < 10000; p++) {
        ll baggage = 0;
        ll trucks = k;

        for (ll w : W) {
            baggage += w;
            if (baggage > p) {
                trucks--;
                baggage = w;
            }

    }



    return 0;
}