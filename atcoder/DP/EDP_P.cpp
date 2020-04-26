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
vector<vector<int>> E(100100, vector<int>());
vector<bool> used(100100, false);
vector<vector<ll>> dp(100100, vector<ll>(2, 0));

void rec(int x) {
    used.at(x) = true;
    ll b = 1, w = 1;

    for (int i = 0; i < E.at(x).size(); i++) {
        if (!used.at(E.at(x).at(i))) rec(E.at(x).at(i));
        if (dp.at(E.at(x).at(i)).at(0) == 0) continue;

        b *= dp.at(E.at(x).at(i)).at(1);
        b %= mod;
        w *= dp.at(E.at(x).at(i)).at(0) + dp.at(E.at(x).at(i)).at(1);
        w %= mod;

    }

    dp.at(x).at(0) = b;
    dp.at(x).at(1) = w;

    return;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    REP(i, N - 1) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        E.at(x).push_back(y);
        E.at(y).push_back(x);
    }

    rec(0);

    cout << (dp.at(0).at(0) + dp.at(0).at(1)) % mod << endl;
    
    return 0;
}