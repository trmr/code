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

string K;
int D;

vector<vector<vector<ll>>> dp(10100, vector<vector<ll>>(110, vector<ll>(2, 0)));

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> K;
    cin >> D;

    int N = K.length();

    dp.at(0).at(0).at(0) = 1;

    REP(digit, N) REP(d, D) REP(isless, 2) {
        int c = K.at(digit) - '0';
        REP(next, 10) {
            if (next < c) {
                dp.at(digit + 1).at((d + next) % D).at(1) += dp.at(digit).at(d).at(isless);
                dp.at(digit + 1).at((d + next) % D).at(1) %= mod; 
            } else if (next == c) {
                dp.at(digit + 1).at((d + next) % D).at(isless) += dp.at(digit).at(d).at(isless);
                dp.at(digit + 1).at((d + next) % D).at(isless) %= mod;
            } else {
                if (isless) {
                    dp.at(digit + 1).at((d + next) % D).at(isless) += dp.at(digit).at(d).at(isless);
                    dp.at(digit + 1).at((d + next) % D).at(isless) %= mod;
                }
            }

        }

    }

    cout << (dp.at(N).at(0).at(0) + dp.at(N).at(0).at(1) - 1 + mod) % mod << endl;
    
    return 0;
}