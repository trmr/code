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

int H, W;
vector<vector<char>> a(1010, vector<char>(1010));
vector<vector<ll>> dp(1010, vector<ll>(1010, 0));

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> H >> W;

    REP(i, H) {
        string line; cin >> line;
        REP(j, W) {
            a.at(i).at(j) = line.at(j);
        }
    }

    dp[0][0] = 1;

    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (y < 0 || H <= y || x < 0 || W <= x) {
                continue;
            }
    
            if (a[y][x] == '#') continue;

            if (y >= 1 && a[y - 1][x] == '.') {
                dp[y][x] = dp[y - 1][x];
                dp[y][x] %= mod;
            }
            if (x >= 1 && a[y][x - 1] == '.') {
                dp[y][x] = dp[y][x - 1];
                dp[y][x] %= mod;
            }

            if (y >= 1 && a[y - 1][x] == '.') {
                if (x >= 1 && a[y][x - 1] == '.') {
                    dp[y][x] = dp[y - 1][x] + dp[y][x - 1];
                    dp[y][x] %= mod;
                }
            }            
        }
    }

    cout << dp[H - 1] [W - 1] << endl;
    
    return 0;
}