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

int N, ans;
vector<vector<int>> A(30, vector<int>(30, 0));
vector<vector<int>> G(30, vector<int>());
vector<int> dp((1<<22), 0);
vector<bool> used(30);
vector<int> match(30);


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    REP(i, N) {
        REP(j, N) {
            cin >> A.at(i).at(j);
        }
    }

    dp.at(0) = 1;

    for (ll S = 0; S < 1 << N; S++) {
        auto bs = bitset<30>(S);
        int cnt = bs.count() - 1;
        for (int i = 0; i < N; i++) {
            if (bs.test(i) && A.at(cnt).at(i)) {
                dp.at(S) += dp.at(S ^ (1 << i));
                dp.at(S) %= mod;
            }
        }
    }

    cout << dp.at((1 << N) - 1) << endl;
    
    return 0;
}