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



int N;
VI L;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    L.resize(N + 1, 100100);

    REP(i, N) {
        int a;
        cin >> a;

        for (int j = 0; j < N; j++) {
            if (a <= L[j]) {
                L[j] = a;
                break;
            }
        }
    }

    if (L[N-1] != 100100) {
        cout << N << endl;
        return 0;
    }

    REP(i, N) {
        if (L[i] == 100100) {
            cout << i << endl;
            break;
        }
    }




    return 0;
}