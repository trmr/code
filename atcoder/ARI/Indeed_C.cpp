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

int N, M;

vector<vector<vector<ll>>> dp(110, vector<vector<ll>>(110, vector<ll>(110, 0)));

struct company {
    ll a, b, c, w;
};

struct person {
    ll x, y, z;
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    vector<company> comv;
    vector<person> perv;

    REP(i, N) {
        ll a, b,c, w;
        cin >> a >> b >> c >> w;
        chmax(dp[a][b][c],w); 
    }

    REP(i, M) {
        ll x, y, z;
        cin >> x >> y >> z;
        person per = {x, y, z};
        perv.push_back(per);
    }


    for (int a = 0; a <= 100; a++) {
        for (int b = 0; b <= 100; b++) {
            for (int c = 0; c <= 100; c++) {

                chmax(dp[a + 1][b][c], dp[a][b][c]);
                chmax(dp[a][b+1][c], dp[a][b][c]);
                chmax(dp[a][b][c+1], dp[a][b][c]);

            }
        }
    }

    for (int i = 0; i < M; i++) {
        cout << dp[perv[i].x][perv[i].y][perv[i].z] << endl;
    }

    return 0;
}