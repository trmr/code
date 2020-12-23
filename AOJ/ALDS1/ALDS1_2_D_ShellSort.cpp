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

ll cnt = 0;
vector<ll> G;

void insertionSort(vector<ll>& A, ll n, ll g) {
    for (int i = g; i < n; i++) {
        ll v = A[i];
        ll j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j + g] = v;
    }
}

void shellSort(vector<ll>& A, ll n) {
    ll i = 1;
    ll m = 0;
    while(1) {
        G.push_back(i);
        m++;
        i = 3*i + 1;
        if (i >= n) break;
    }
    for (int i = m - 1; i >= 0; i--) {
        insertionSort(A, n, G[i]);
    }

    cout << m << endl;
    for (int i = m - 1; i > 0; i--) cout << G[i] << " ";
    cout << G[0] << endl;


}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n;
    vector<ll> A;
    cin >> n;
    A.resize(n);
    REP(i, n) cin >> A[i];

    shellSort(A, n);

    cout << cnt << endl;
    REP(i, n) cout << A[i] << endl;

    return 0;
}