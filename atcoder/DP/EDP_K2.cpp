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
vector<int> a;
vector<bool> dp;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> K;
    a.resize(N);
    dp.resize(K);

    REP(i, N) cin >> a.at(i);

    for (int i = 0; i < a[0]; i++) {
        dp.at(i) = false;
    }

    for (int i = a[0]; i <= K; i++) {
        bool flag = false;
        for (int j = 0; j < N; j++) {
            if (i - a[j] < 0) continue;
            if (dp.at(i - a[j]) == false) flag = true;
        }
        dp[i] = flag;
    }

    if (dp[K]) cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;
}