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

int N, K;
vector<int> A;
vector<int> dp(100100, 0);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    A.resize(N, 0);
    REP(i, N) cin >> A.at(i);

    dp.at(0) = -1;

    for (int i = 0; i <= K; i++) {
        bool isloser = true;
        for (int j = 0; j < N; j++) {
            if (i >= A.at(j)) {
                if (dp.at(i - A.at(j)) == -1) {
                    dp.at(i) = A.at(j);
                    isloser = false;
                    break;
                }

            }
        }
        if (isloser) dp.at(i) = -1;
    }

    if (dp.at(K) == -1) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
    
    return 0;
}