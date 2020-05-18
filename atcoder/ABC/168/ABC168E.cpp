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
const int mod = 1000000007;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

ll modpow(ll a, ll n) {
   ll res = 1;
   while (n > 0) {
      if (n & 1) {
         res *= a;
         res %= mod;
      }
      a *= a;
      a %= mod;

      n >>= 1;
   }
   return res;
}

ll N;
vector<ll> A, B;

vector<double> C;
map<double, ll> D;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    A.resize(N + 1);
    B.resize(N + 1);

    REP(i, N) {
        cin >> A[i] >> B[i];
    }

    C.resize(N + 1);

    REP(i, N) {
        C[i] = (double)A[i] / B[i];
        D[(double)B[i] / A[i] * (-1)] += 1;
    }

    ll ng = 0;

    REP(i, N) {
        ng += D[C[i]]; 
        ng %= mod;
    }

    ng /= 2;

    ll ans = modpow(2, N) - 1;

    REP(i, ng) {
        ans = (ans + mod - modpow(2, N - 2)) % mod;
    } 


    cout << ans << endl;

    return 0;
}