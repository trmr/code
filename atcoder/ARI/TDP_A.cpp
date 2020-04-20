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
vector<int> P(110, 0);
vector<bool> dp(10100, false);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    REP(i, N) cin >> P.at(i);

    dp.at(0) = true;

    for (int i = 0; i < N; i++) {
        for (int point = 10000; 0 <= point; point--) {
            if (dp.at(point)) dp.at(point + P.at(i)) = true;
        }
    }

    int ans = count(ALL(dp), true);

    cout << ans << endl;

    return 0;
}