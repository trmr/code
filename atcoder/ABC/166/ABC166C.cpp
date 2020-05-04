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
vector<ll> H;
vector<vector<int>> AB(100100);
vector<bool> used(100100, false);

void rec(int i) {
    if (used.at(i)) return;
    used.at(i) = true;
    for (int j = 0; j < AB.at(i).size(); j++) {
        rec(AB.at(i).at(j));
    }
    return;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    H.resize(N);
    REP(i, N) {
        cin >> H.at(i);
    }

    REP(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        AB.at(a).push_back(b);
        AB.at(b).push_back(a);
    }

    ll ans = 0;

    REP(i, N) {
        ll h = H.at(i);
        bool flag = true;
        for (auto x:AB.at(i)) {
            if (h <= H.at(x)) {
                flag = false;
                break;
            }
        }
        if (flag) ans++;
    }

    cout << ans << endl;

    return 0;
}