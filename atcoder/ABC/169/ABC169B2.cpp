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

ll N;
vector<ll> A;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    A.resize(N);

    bool flag = false;

    REP(i, N) {
        cin >> A[i];
        if (A[i] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    ll AA = 1;
    REP(i, N) {
        if (AA > 1000000000000000000 / A[i]) {
            flag = true;
            break;
        }
        AA *= A[i];
    }

    if (flag) {
        cout << -1 << endl;

    } else {
        cout << AA << endl;
    }

    return 0;
}