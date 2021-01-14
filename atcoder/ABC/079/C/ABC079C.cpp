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

    char A,B,C,D;
    int S[4];
    cin >> A >> B >> C >> D;
    S[0] = A - '0';
    S[1] = B - '0';
    S[2] = C - '0';
    S[3] = D - '0';

    bool flag = false;

    for (int i = 0; i < (1 << 3); i++) {
        int sum = S[0];
        bitset<3> bs(i);
        for (int j = 0; j < 3; j++) {
            if (bs.test(j)) {
                sum += S[j + 1];
            } else {
                sum -= S[j + 1];
            }
        }
        if (sum == 7) {
            flag = true;
            cout << S[0] << (bs.test(0) ? '+' : '-') << S[1] << (bs.test(1) ? '+' : '-') << S[2] << (bs.test(2) ? '+' : '-') << S[3] << "=7" << endl;
            break;
        }
    }

    return 0;
}