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
vector<int> H(100010);
vector<int> H1(100010);
vector<int> H2(100010);
int MAX_N = 100000;

vector<ll> dp(100010, INF);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;
    REP(i, N) {
        cin >> H.at(i);
    }
    for (int i = 0; i < N - 1; i++) {
        H1.at(i) = abs(H.at(i) - H.at(i + 1));
    }
    for (int i = 0; i < N - 2; i++) {
        H2.at(i) = abs(H.at(i) - H.at(i + 2));
    }

    dp.at(0) = 0;

    for (int i = 0; i < N; i++){
        chmin(dp.at(i + 1), dp.at(i) + H1.at(i));
        chmin(dp.at(i + 2), dp.at(i) + H2.at(i));
    }

    cout << dp.at(N-1) << endl; 

    return 0;
}