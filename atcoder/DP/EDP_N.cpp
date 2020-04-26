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
vector<ll> A;
vector<vector<ll>> dp(400, vector<ll>(400, 0));


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    A.resize(N + 1, 0);
    REP(i, N) cin >> A.at(i);

    REP(i, N) dp.at(i).at(i) = 0;

    for (int len = 1; len < N; len++) {
        for (int left = 0; left < N - len; left++) {
            ll tmp = INF;
            ll sum = 0;
            int right = left + len;
            for (int idx = left; idx < right; idx++) {
                tmp = min(tmp, dp.at(left).at(idx) + dp.at(idx + 1).at(right));
                sum  += A.at(idx);
            }
            sum += A.at(right);
            dp.at(left).at(right) = tmp + sum;

        }
    }

    cout << dp.at(0).at(N - 1) << endl;

    
    return 0;
}