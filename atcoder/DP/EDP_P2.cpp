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

int N;
vector<vector<int>> G;
vector<vector<ll>> dp;

void rec(int parent, int current) {
    if (G[current].size() == 1 && G[current][0] == parent) {
        dp[current][0] = 1;
        dp[current][1] = 1;
    }

    if (G[current].size() == 0) {
        dp[current][0] = 1;
        dp[current][1] = 1;
    }

    for (int i = 0; i < G[current].size(); i++) {
        int next = G[current][i];
        if (next == parent) continue;
        rec(current, next);
    }
    if (parent == -1 ) return;
    dp[parent][0] *= dp[current][1];
    dp[parent][0] %= mod;
    dp[parent][1] *= (dp[current][1] + dp[current][0])%mod;
    dp[parent][1] %= mod;
    return;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    G.assign(N, vector<int>());

    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dp.assign(N + 1, vector<ll>(2, 1));

    rec(-1, 0);

    cout << (dp[0][0] + dp[0][1]) % mod << endl;
    
    return 0;
}