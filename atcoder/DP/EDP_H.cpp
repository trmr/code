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



vector<vector<char>> A(1010, vector<char>(1010));
vector<vector<int>> dp(1010, vector<int>(1010, 0));

int H, W;
ll ans;

void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> H >> W;

    for (int h = 0; h < H; h++) {
        string line; cin >> line;
        for (int w = 0; w < W; w++) {
            A.at(h).at(w) = line.at(w);
        }
    }

    dp.at(0).at(0) = 1;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i + 1 < H && A.at(i + 1).at(j) == '.') add(dp.at(i + 1).at(j), dp.at(i).at(j));
            if (j + 1 < W && A.at(i).at(j + 1) == '.') add(dp.at(i).at(j + 1), dp.at(i).at(j));
        }
    }

    cout << dp.at(H - 1).at(W - 1) << endl;

    return 0;
}
