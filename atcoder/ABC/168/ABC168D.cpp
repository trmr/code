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

ll N , M;
Graph G;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    G.assign(N + 1, vector<ll>());

    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<pair<ll, ll>> que;

    vector<ll> ans(N + 1, -1);

    que.push(make_pair(0, -1));

    while (!que.empty()) {
        pair<ll, ll> p = que.front();
        que.pop();
        ll cur = p.first;
        ll par = p.second;
        if (ans[cur] != -1) continue;
        ans[cur] = par;
        for (int i = 0; i < G[cur].size(); i++) {
            ll next = G[cur][i];
            pair<ll, ll> nextp = make_pair(next, cur);
            que.push(nextp);
        }
    }

    bool flag = true;

    for (int i = 1; i < N; i++) {
        if (ans[i] == -1) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "Yes" << endl;
        for (int i = 1; i < N; i++) {
            cout << ans[i] + 1 << endl;
        }
    }else {
        cout << "No" << endl;
    }
    
    return 0;
}