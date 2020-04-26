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
vector<int> A;
vector<vector<ll>> dp(110, vector<ll>(100100, 0));
vector<ll> S(100100, 0);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    A.resize(N);
    REP(i, N) cin >> A.at(i);

    REP(i, A.at(0) + 1) dp.at(0).at(i) = 1;
    REP(i, K + 1) S.at(i + 1) = S.at(i) + dp.at(0).at(i);

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            dp.at(i).at(j) = (S.at(j + 1) - S.at(max(0, j - A.at(i))) + mod) % mod;
        }
        for (int j = 0; j <= K; j++) {
            S.at(j + 1) = (S.at(j) + dp.at(i).at(j) + mod) % mod;
        }
    }

    cout << dp.at(N - 1).at(K) << endl;
    
    return 0;
}