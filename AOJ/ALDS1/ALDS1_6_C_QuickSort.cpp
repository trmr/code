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
    char type;
    ll num;
};

void merge(vector<Card>& A, ll left, ll mid, ll right) {
    ll n1 = mid - left;
    ll n2 = right - mid;
    vector<Card> L, R;
    L.resize(n1 + 1);
    R.resize(n2 + 1);
    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }
    L[n1].num = INF;
    R[n2].num = INF;
    ll i = 0;
    ll j = 0;
    for (int k = left; k < right; k++) {
        if (L[i].num <= R[j].num) {
            A[k] = L[i];
            i = i + 1;
        } else {
            A[k] = R[j];
            j = j + 1;
        }
    }
}

void mergeSort(vector<Card> &A, ll left, ll right) {
    if (left + 1 < right) {
        ll mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}


ll partition(vector<Card> &A, ll p, ll r) {
    ll x = A[r].num;
    ll i = p - 1;

    for (int j = p; j < r; j++) {
        if (A[j].num <= x) {
            i = i + 1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i + 1;
}

void quicksort(vector<Card> &A, ll p, ll r) {
    if (p < r) {
        ll q = partition(A, p, r);
        quicksort(A, p, q -1);
        quicksort(A, q + 1, r);
    }
}



int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<Card> A(n);

    REP(i, n) {
        cin >> A[i].type >> A[i].num;
    }

    vector<Card> B = A;

    quicksort(A, 0, n-1);
    mergeSort(B, 0, n);

    bool flag = true;
    REP(i, n) {
        if (A[i].type != B[i].type) flag = false;
    }
    if (flag) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }

    REP(i, n){
        cout << A[i].type << " " << A[i].num << endl;
    }





    return 0;
}