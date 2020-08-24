#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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

using Edge = pair<ll, ll>;
using Graph = vector<vector<Edge>>;



vector<VVL> v;
ll N, Q, K;
VL dp;

Graph G;

ll x, y;


void rec(ll cur, ll cost, ll past) {
    dp[cur] = min(dp[cur], cost);
    
    for (auto e : G[cur]) {
        if (e.first == past) continue;
        rec(e.first, cost + e.second, cur);
    }
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    G.resize(N);
    dp.assign(N + 1, INF);

    REP(i, N - 1) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    cin >> Q >> K;
    K--;

    rec(K, 0, -1);

    for (int q = 0; q < Q; q++) {
        int x, y; cin >> x >> y; x--; y--;
        cout << dp[x] + dp[y] << endl;
    }




    



    return 0;
}