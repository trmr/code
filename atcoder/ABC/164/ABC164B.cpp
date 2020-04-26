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

int A, B, C, D;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> A >> B >> C >> D;

    REP(i, 101) {
        C -= B;
        if (C <= 0) {
            cout << "Yes" << endl;
            break;
        }
        A -= D;
        if (A <= 0) {
            cout << "No" << endl;
            break;
        }
    }
    
    return 0;
}