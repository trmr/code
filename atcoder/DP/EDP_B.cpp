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
vector<int> h(100010);
vector<int> dp(100010, INT32_MAX);


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> K;
    REP(i, N) cin >> h.at(i);

    dp.at(0) = 0;

    for (int i = 1; i < N; i++) {
        for(int j = i - K; j < i; j++) {
            if (j < 0) continue;
            chmin(dp.at(i), dp.at(j) + abs(h.at(j) - h.at(i)));
        }
    }

    cout << dp.at(N - 1) << endl;

    return 0;
}