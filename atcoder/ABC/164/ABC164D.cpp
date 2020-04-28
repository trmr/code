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
vector<int> cnt(2020, 0);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> S;

    ll N = S.size();
    reverse(ALL(S));

    ll total = 0;
    int ten = 1;

    cnt.at(0) = 1;

    REP(i, N) {
        total = (total + (S.at(i) - '0') * ten) % 2019;
        cnt.at(total)++;

        ten = (ten * 10) % 2019;    
    }

    ll ans = 0;

    REP(i, 2020) {
        ans += cnt.at(i) * (cnt.at(i) - 1) / 2;
    }

    cout << ans << endl;
    
    return 0;
}