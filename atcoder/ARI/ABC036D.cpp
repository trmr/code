#include <bits/stdc++.h>
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

ll N;
VVL v;
VVL dp;

ll rec(ll cur, ll color, ll past) {
    if (dp[cur][color] > 0) return dp[cur][color];
    if (past != -1 && v[cur].size() == 1) return dp[cur][color] = 1;

    ll res = 1;

    REP(i, v[cur].size()) {
        ll next = v[cur][i];
        if (next == past) continue;
        if (color) {
            res *= rec(next, 0, cur);
        } else {
            res *= rec(next, 1, cur) + rec(next, 0, cur);
        }
        res %= MOD;
    }
    return dp[cur][color] = res;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    v.assign(N + 1, VL());
    dp.assign(N + 1, VL(2));

    REP(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }

    ll ans = 0;

    ans = rec(0, 1, -1) + rec(0, 0, -1);
    ans %= MOD;

    cout << ans << endl;

    return 0;
}