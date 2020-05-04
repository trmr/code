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

int N, M, Q;
vector<int> a, b, c, d;
vector<int> A(11);

ll maxscore = 0;

void rec(int i) {
    if (i == N) {
        ll total = 0;
        REP (j, Q) {
            if ((A.at(b.at(j)) - A.at(a.at(j))) == c.at(j)) total += d.at(j);
        }
        chmax(maxscore, total);
        return;
    }

    for (A.at(i) = A.at(i - 1); A.at(i) <= M; A.at(i)++) {
        rec(i + 1);
    }

    return;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> Q;

    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);

    REP(i, Q) {
        int aa, bb, cc, dd;
        cin >> aa >> bb >> cc >> dd;
        aa--; bb--;
        a.at(i) = aa; b.at(i) = bb; c.at(i) = cc; d.at(i) = dd;
    }

    A.at(0) = 1;

    rec(1);

    cout << maxscore << endl;

    return 0;
}