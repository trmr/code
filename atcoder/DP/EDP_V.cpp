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
vector<vector<ll>> dp(100100, vector<ll>());
vector<ll> ans(100100);

ll dfs1(int v, int p) {
    ll res = 1;
    for (int u = 0; u < G[v].size(); u++) {
        if (G[v][u] != p) {
            dp[v][u] = dfs1(G[v][u], v);
            res *= (dp[v][u] + 1);
            res %= M;
        }
    }
    return res;
}

void dfs2(int v, int p, ll dp_p) {
    int n = G[v].size();

    for (int i = 0; i < G[v].size(); i++) {
        if (G[v][i] == p) {
            dp[v][i] = dp_p;
            break;
        }
    }

    vector<ll> l(n), r(n);

    for (int i = 0; i < n; i++) {
        l[i] = r[i] = (dp[v][i] + 1) % M;
    }

    for (int i = 1; i < n; i++) {
        l[i] *= l[i - 1];
        l[i] %= M;
    }
    for (int i = n - 2; i >= 0; i--) {
        r[i] *= r[i + 1];
        r[i] %= M;
    }

    for (int i = 0; i < n; i++) {
        int nv = G[v][i];
        if (nv == p) continue;

        ll dp_v = 1;
        if (i != 0) {
            dp_v *= l[i - 1];
            dp_v %= M;
        }
        if (i != n - 1) {
            dp_v *= r[i + 1];
            dp_v %= M;
        }
        dfs2(nv, v, dp_v);

    }
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;

    G.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dp.resize(N);
    for (int i = 0; i < N; i++) {
        dp[i].resize(G[i].size());
    }

    dfs1(0, -1);
    dfs2(0, -1, 0);

    REP(i, N) {
        ll ans = 1;
        for (ll dp_i: dp[i]) {
            ans *= (dp_i + 1);
            ans %= M;
        }
        cout << ans << endl;
    }

    return 0;
}