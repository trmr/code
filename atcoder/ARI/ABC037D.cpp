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

ll H, W;
VVL a;
VVL memo;
VL X = {-1, 0, 1, 0};
VL Y = {0, 1, 0, -1};

ll rec(ll h, ll w) {
    if (memo[h][w] != 0) return memo[h][w];

    ll ret = 0;

    REP(i, 4) {
        ll y = h + Y[i];
        ll x = w + X[i];
        if ((y < 0) || (H <= y) || (x < 0) || (W <= x)) continue;
        if (a[h][w] >= a[y][x]) continue;

        if (memo[y][x] != 0) {
            ret += memo[y][x];
            ret %= MOD;
        } else {
            ret += rec(y, x);
            ret %= MOD;
        }
    }
    return memo[h][w] = (ret + 1) % MOD;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> H >> W;

    a.resize(H, VL(W));
    memo.resize(H, VL(W, 0));

    REP(i, H) {
        REP (j, W) {
            cin >> a[i][j];
        }
    }

    ll ans = 0;

    REP(i, H) {
        REP(j, W) {
            ans += rec(i, j);
            ans %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}