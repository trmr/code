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

string S, T;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> S;
    cin >> T;

    bool flag = true;

    for (int i = 0; i < S.size(); i++) {
        if (S[i] != T[i]) flag = false;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}