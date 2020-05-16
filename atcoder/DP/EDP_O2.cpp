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
vector<vector<int>> a;
vector<ll> dp;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    a.assign(N + 1, vector<int>(N + 1, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    dp.resize(1 << N + 1);
    dp[0] = 1;

    for (ll i = 0; i < 1 << N; i++) {
        bitset<21> bs(i);
        int men = bs.count() - 1;
        for (int j = 0; j < N; j++) {
            if (bs.test(j) && a[men][j]) {
                dp[i] += dp[bs.flip(j).to_ullong()];
                dp[i] %= mod;
            }
        }
    }

    cout << dp[(1 << N) - 1] << endl;
    
    return 0;
}