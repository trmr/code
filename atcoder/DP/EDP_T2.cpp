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
string s;
vector<vector<ll>> dp;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> s;

    dp.assign(N + 1, vector<ll>(N + 1, 0));
    REP(i, N) dp[0][i] = 1;

    for (int i = 0; i < N; i++) {
        vector<ll> S(N + 1, 0);
        for (int j = 0; j < N; j++) {
            S[j + 1] = S[j] + dp[i][j];
            S[j + 1] %= mod;
        }
        for (int j = 0; j < N; j++) {
            if (s[i] == '>') {
                dp[i + 1][j] = S[j + 1];
            } else if (s[i] == '<') {
                dp[i + 1][j] = (S[N - i] - S[j + 1] + mod) % mod;
            }
        }
    }

    cout << dp[N - 1][0] << endl;


    
    return 0;
}