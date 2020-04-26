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

int N, M;


Graph G;
vector<int> dp(100100, -1);
vector<int> deg;

int rec(int v) {
    if (dp.at(v) != -1) return dp.at(v);

    int res = 0;
    for (auto nv : G.at(v)) {
        chmax(res, rec(nv) + 1);

    }
    return dp.at(v) = res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    G.assign(N, vector<int>());
    deg.assign(N, 0);
    REP(i, M) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G.at(x).push_back(y);
        deg.at(y)++;
    }

    queue<int> que;
    for (int v = 0; v < N; v++) if (deg.at(v) == 0) que.push(v);

    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (auto nv : G.at(v)) {
            deg.at(nv)--;
            if (deg.at(nv) == 0) {
                que.push(nv);
                chmax(dp.at(nv), dp.at(v) + 1);
            }
        }
    }

    int ans = 0;
    for (int v = 0; v < N; v++) {
        chmax(ans, dp.at(v));
    }

    cout << ans << endl;
    
    return 0;
}