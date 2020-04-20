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

ll N, W;
vector<ll> w(110);
vector<ll> v(110);
vector<vector<ll>> dp(110, vector<ll>(100100, INF));


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> W;
    REP(i, N) cin >> w.at(i) >> v.at(i);

    dp.at(0).at(0) = 0;

    for (int i = 0; i < N; i++) {
        for (int sum_v = 0; sum_v < 100100; sum_v++) {
            if (v.at(i) <= sum_v) {
                chmin(dp.at(i + 1).at(sum_v), dp.at(i).at(sum_v - v.at(i)) + w.at(i));
            }
            chmin(dp.at(i + 1).at(sum_v), dp.at(i).at(sum_v));
        }
    }

    ll ans = 0;
    for (int sum_v = 0; sum_v < 100100; sum_v++) {
        if (dp.at(N).at(sum_v) <= W) ans = sum_v;
    }

    cout << ans << endl;
    
    return 0;
}