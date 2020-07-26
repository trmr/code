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

int n;
vector<int> s, l, p;
int m;
vector<int> w;

vector<int> dp(400, 0);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    s.resize(n + 1);
    l.resize(n + 1);
    p.resize(n + 1);
    REP(i, n) {
        cin >> s[i] >> l[i] >> p[i];
    }
    cin >> m;
    w.resize(m + 1);
    REP(i, m) {
        cin >> w[i];
    }

    dp[0] = 0;

    for (int i = 1; i < 400; i++) {
        for (int j = 0; j < n; j++) {
            chmax(dp[i], dp[i - 1]);
            if (i >= s[j]) {
                chmax(dp[i], dp[i - s[j]] + p[j]);
            }
        }
    }

    bool err = false;

    vector<int> ans(m + 1, 0);

    for (int i = 0; i < m; i++) {
        if (dp[w[i]] == 0) {
            err = true;
            break;
        } else {
            ans[i] = dp[w[i]];
        }
    }

    if (err) {
        cout << -1 << endl; return 0;
    }

    for(int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }





    return 0;
}