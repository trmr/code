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
vector<int> a;
vector<vector<ll>> S;
vector<vector<ll>> dp;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    a.resize(N);
    REP(i, N) cin >> a[i];

    dp.assign(N + 10, vector<ll>(K + 10, 0));
    S.assign(N + 10, vector<ll>(K + 10, 0));


    for (int i = 0; i < a[0] + 1; i++) {
        dp[0][i] = 1;
    }

    for(int i = 0; i < K + 1; i++) {
        S[0][i + 1] = S[0][i] + dp[0][i];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            if (j > a[i]) {
                dp[i][j] = (S[i - 1][j + 1] - S[i - 1][j - a[i]] + mod) % mod;
                dp[i][j] %= mod;
            } else {
                dp[i][j] = S[i - 1][j + 1];
                dp[i][j] %= mod;
            }
        }
        for (int j = 0; j <= K; j++) {
            S[i][j + 1] = S[i][j] + dp[i][j];
            S[i][j + 1] %= mod;
        }
    }

    cout << dp[N - 1][K] << endl;
    
    return 0;
}