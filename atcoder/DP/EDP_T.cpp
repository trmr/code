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
string s;
vector<vector<ll>> dp(3010, vector<ll>(3010, 0));

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    cin >> s;

    for (int i = 0; i < N; i++) {
        dp.at(0).at(i) = 1;
    }

    for (int i = 0; i < N - 1; i++) {
        vector<int> sum(3010, 0);
        sum.at(0) = 0;
        for (int j = 0; j <= N - i; j++) {
            sum.at(j + 1) = (sum.at(j) + dp.at(i).at(j)) % mod;
        }

        if (s.at(i) == '<') {
            for (int j = 0; j < N - i; j++) {
                dp.at(i + 1).at(j) = (sum.at(N - i) - sum.at(j + 1) + mod) % mod;
            }
        }
        if (s.at(i) == '>') {
            for (int j = 0; j < N - i; j++) {
                dp.at(i + 1).at(j) = sum.at(j + 1);
            }
        }
    }

    cout << dp.at(N - 1).at(0) << endl;

    
    return 0;
}