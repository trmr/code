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

int N, M, X;
vector<int> C(12);
vector<vector<int>> A(12, vector<int>(12, 0));

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> X;

    for (int i = 0; i < N; i++) {
        cin >> C.at(i);
        for (int j = 0; j < M; j++) {
            cin >> A.at(i).at(j);
        }
    }

    ll mincost = INF;

    for (int i = 0; i < (1 << 12); i++) {
        bitset<12> bs(i);

        ll cost = 0;
        vector<ll> us(M, 0);

        for (int j = 0; j < 12; j++) {
            if (bs.test(j)) {
                cost += C.at(j);
                for (int k = 0; k < M; k++) {
                    us.at(k) += A.at(j).at(k);
                }
            }
        }

        bool flag = true;

        for (int j = 0; j < M; j++) {
            if (us.at(j) < X) {
                flag = false;
                break;
            }
        }

        if (flag) {
            chmin(mincost, cost);
        }

    }

    if (mincost == INF) {
        cout << -1 << endl;
    } else {
        cout << mincost << endl;
    }

    
    return 0;
}