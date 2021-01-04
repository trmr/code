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

ll H;

#define left(i) (i * 2)
#define right(i) (i * 2 + 1)

void maxHeapify(vector<ll> &A, ll i) {
    ll l = left(i);
    ll r = right(i);
    ll largest;
    if (l <= H && A[l] > A[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if (r <= H && A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(A, largest);
    }

}

void buildMaxHeap(vector<ll> &A) {
    for (int i = H / 2; i > 0; i--) {
        maxHeapify(A, i);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n;
    vector<ll> A;
    cin >> n;
    H = n + 1;
    A.resize(2 * H);

    for (int i = 1; i < H; i++) {
        cin >> A[i];
    }

    buildMaxHeap(A);

    for (int i = 1; i < H; i++) {
        cout << " " << A[i];
    }
    cout << endl;
    
    return 0;
}