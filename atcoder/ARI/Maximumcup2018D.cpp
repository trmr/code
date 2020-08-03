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
const int mod = 1000000007;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

ll N, M, L, X;
VL a;
VVL dp;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> L >> X;
    a.resize(N+1);
    REP(i, N) {
        cin >> a[i+1];
    }

    dp.assign(N+1, VL(M+1, INF));

    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ll c = (j + a[i+1])%M;
            if (dp[i][j] + a[i+1] < X*M) {
                dp[i+1][c] = min(dp[i+1][c], dp[i][j] + a[i+1]); 
            }
            chmin(dp[i+1][c], dp[i][c]);
        }

    }

    if (dp[N][L] != INF) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
}