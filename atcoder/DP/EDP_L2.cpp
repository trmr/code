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
vector<ll> a;
vector<vector<ll>> dp;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    a.resize(N);
    REP(i, N) cin >> a.at(i);
    dp.assign(N+1, vector<ll>(N+1, 0));

    REP(i, N) dp.at(i).at(i) = 0;

    for (int len = 1; len <= N; len++) {
        for (int l = 0; l + len <= N; l++) {
            int r = l + len;
            if ((N - len) % 2 == 0) {
                dp.at(l).at(r) = max(dp.at(l + 1).at(r) + a.at(l), dp.at(l).at(r - 1) + a.at(r - 1));
            } else {
                dp.at(l).at(r) = min(dp.at(l + 1).at(r) - a.at(l), dp.at(l).at(r - 1) - a.at(r - 1));
            }
        }
    }

    cout << dp.at(0).at(N) << endl;

    return 0;
}