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

int K;
int A, B;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> K;
    cin >> A >> B;

    bool flag = false;

    int k = K;

    while (k <= 1000) {
        if (A <= k && k <= B) {
            flag = true;
            break;
        }
        k += K;
    }

    if (flag) cout << "OK" << endl;
    else cout << "NG" << endl;
    
    return 0;
}