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



int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int D;
    ll G;

    cin >> D >> G;

    vector<int> p(D), c(D);

    REP(i, D) cin >> p[i] >> c[i];

    ll ans = INF;

    for (int i = 0; i < (1 << D); i++) {
        bitset<10> bs(i);
        ll totalp = 0;
        ll totaln = 0;
        for (int j = 0; j < D; j++) {
            if (bs.test(j)) {
                totalp += (p[j] * 100 * (j + 1));
                totalp += c[j];
                totaln += p[j];
            }
        }
        for (int j = D - 1; j >= 0; j--) {
            if (totalp >= G) {
                chmin(ans, totaln);
                break;
            }
            if (!bs.test(j)) {
                for (int k = 0; k < p[j]; k++) {
                    totalp += 100 * (j + 1);
                    totaln++;
                    if (totalp >= G) {
                        chmin(ans, totaln);
                        break;
                    }
                }

            }
        }
    }

    cout << ans << endl;



    return 0;
}