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

bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; i++) {
        if (N % i == 0) return false;
    }
    return true;
}

vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            res.push_back(i);
            if (N / i != i) res.push_back(N / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

vector<pair<long long, long long>> prime_factorize(long long N) {
    vector<pair<long long, long long>> res;
    for (long long a = 2; a * a <= N; a++) {
        if (N % a != 0) continue;
        long long ex = 0;

        while (N % a == 0) {
            ex++;
            N /= a;
        }

        res.push_back({a, ex});
    }

    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n; cin >> n;
    ll ans = 0;
    REP(i, n) {
        ll a; cin >> a;
        if (is_prime(a)) ans++;
    }

    cout << ans << endl;
    return 0;
}