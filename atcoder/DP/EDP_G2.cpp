#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using Field = vector<vector<int>>;
using Graph = vector<vector<int>>;
using VI = vector<int>;
using VC = vector<char>;
using PI = pair<int, int>;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const long long INF = 1LL<<60;
const int mod = 1000000007;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

int N, M;
Graph G(100100, vector<int>());
vector<ll> dp(100100);

ll rec(int v) {
    if (G.at(v).empty()) return 0;
    if (dp.at(v) != 0) return dp.at(v);

    ll ret = 0;

    for (auto nv : G[v]) {
        chmax(ret, rec(nv));
    }
    return dp.at(v) = ret + 1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    REP(i, M) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        chmax(ans, rec(i));
    }

    cout << ans << endl;
    
    return 0;
}