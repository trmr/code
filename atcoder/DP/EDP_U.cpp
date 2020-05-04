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
vector<vector<ll>> a(20, vector<ll>(20, 0));
vector<ll> dp(1 << 16);
vector<ll> SCORE(1 << 16);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    REP(i, N) REP(j, N) {
        cin >> a.at(i).at(j);
    }

    for (int use = 0; use < (1 << N); use++) {
        auto bituse = bitset<20>(use);
        ll score = 0;
        REP(i, N) {
            for (int j = i; j < N; j++) {
                if (bituse.test(i) && bituse.test(j)) {
                    score += a.at(i).at(j);
                }
            }
        }
        SCORE.at(use) = score;
    }

    for (int used = 0; used < (1 << N); used++) {
        int unused = used ^ ((1 << N) - 1);
        for (int use = unused; use > 0; use = (use - 1) & unused) {
            ll next = dp.at(used) + SCORE.at(use);
            chmax(dp.at(use | used), next);
        }
    }

    cout << dp.at((1 << N) - 1) << endl;
    
    return 0;
}