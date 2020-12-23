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

struct Card {
    char suit;
    ll value;
};

ll selectionSort(vector<Card>& A, ll N) {
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        ll minj = i;
        for (int j = i; j < N; j++) {
            if (A[j].value < A[minj].value) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(A[i], A[minj]);
            cnt++;
        }

    }
    return cnt;
}


ll bubbleSort(vector<Card>& A, ll N)  {
    ll count = 0;
    bool flag = 1;
    while (flag) {
        flag = 0;
        for (int j = N - 1; j > 0; j--) {
            if (A[j].value < A[j - 1].value) {
                swap(A[j], A[j - 1]);
                flag = 1;
                count++;
            }
        }
    }
    return count;
}



int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n;
    vector<Card> A, B;
    cin >> n;
    A.resize(n);
    B.resize(n);

    REP(i, n) cin >> A[i].suit >> A[i].value;

    B = A;

    bubbleSort(A, n);
    selectionSort(B, n);

    REP(i, n - 1) cout << A[i].suit << A[i].value << " ";
    cout << A[n - 1].suit << A[n - 1].value << endl;
    cout << "Stable" << endl;
    REP(i, n - 1) cout << B[i].suit << B[i].value << " ";
    cout << B[n - 1].suit << B[n - 1].value << endl;
    bool flag = true;
    REP(i, n) {
        if ((A[i].suit != B[i].suit) || (A[i].value != B[i].value)) flag = false;
    }
    if (flag) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }

    return 0;
}