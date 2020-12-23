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

bool binarySearch(ll x, vector<ll> T) {
    ll left = 0;
    ll right = T.size();
    while (left < right) {
        ll mid = (left + right) / 2;
        if (T[mid] == x) return true;
        else if (T[mid] > x) {
            right = mid;
        } else if (T[mid] < x) {
            left = mid + 1;
        }
    }
    return false;

}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n, q;
    set<ll> S;
    vector<ll> T;
    cin >> n;
    REP(i, n) {
        ll x; cin >> x;
        S.insert(x);
    }

    cin >> q;
    REP(i, q) {
        ll x; cin >> x;
        T.push_back(x);
    }

    sort(T.begin(), T.end());

    ll ans = 0;

    for (ll s : S) {
        if (binarySearch(s, T)) ans++;
    }

    cout << ans << endl;

    return 0;
}