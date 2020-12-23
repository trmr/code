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
#include <sstream>
#include <istream>

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



int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    stack<ll> s;
    vector<string> v;

    string s2, tmp;

    getline(cin, s2);
    stringstream ss{s2};

    while (getline(ss, tmp, ' ')) {
        v.push_back(tmp);
    }

    for(string x : v) {
        if (x == "+")  {
            ll b = s.top();
            s.pop();
            ll a = s.top();
            s.pop();
            s.push(a + b);
        } else if (x == "-") {
            ll b = s.top();
            s.pop();
            ll a = s.top();
            s.pop();
            s.push(a - b);
        } else if (x == "*") {
            ll b = s.top();
            s.pop();
            ll a = s.top();
            s.pop();
            s.push(a * b);
        } else {
            s.push(stoi(x));
        }
    }

    cout << s.top() << endl;
    return 0;
}