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

string S;
vector<int> dp(200100, 0);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> S;

    ll N = S.size();

    REP(i, N) {
        for (int j = 1; i + j <= N; j++) {

            string sub = S.substr(i, j);
            ll ls = stoll(sub) % 2019;
            if (ls == 0) {
                dp.at(i)++;
            }
        }
    }

    ll ans = 0;
    REP(i, N) {
        ans += dp.at(i);
    }

    cout << ans << endl;
    
    return 0;
}