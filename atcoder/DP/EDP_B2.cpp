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

int N, K;
vector<ll> h;
vector<ll> dp;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    h.resize(N + K + 10, 0);
    dp.resize(N + K + 10, INF);

    REP(i, N) cin >> h.at(i);

    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
        }
    }

    cout << dp[N - 1] << endl;
    
    return 0;
}