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
vector<int> a(100010);
vector<int> b(100010);
vector<int> c(100010);

vector<vector<ll>> dp(3, vector<ll>(100010, -1));

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    REP(i, N) {
        cin >> a.at(i) >> b.at(i) >> c.at(i);
    }

    dp.at(0).at(0) = dp.at(1).at(0) = dp.at(2).at(0) = 0;

    for (int i = 0; i < N; i++){
        chmax(dp.at(0).at(i + 1), dp.at(1).at(i) + b.at(i));
        chmax(dp.at(0).at(i + 1), dp.at(2).at(i) + c.at(i));
        chmax(dp.at(1).at(i + 1), dp.at(0).at(i) + a.at(i));
        chmax(dp.at(1).at(i + 1), dp.at(2).at(i) + c.at(i));
        chmax(dp.at(2).at(i + 1), dp.at(0).at(i) + a.at(i));
        chmax(dp.at(2).at(i + 1), dp.at(1).at(i) + b.at(i));
    }

    ll ans = 0;

    for (int i = 0; i < 3; i++) {
        chmax(ans, dp.at(i).at(N));
    }

    cout << ans << endl;
    
    return 0;
}