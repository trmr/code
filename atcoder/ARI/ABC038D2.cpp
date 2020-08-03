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

const long long INF = 1<<30;
const int mod = 1000000007;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

template<class T> int LIS(vector<T> a,  bool is_strong = true) {
    const T INF = 1<<30; // to be set appropriately
    int n = (int)a.size();
    vector<T> dp(n, INF);
    for (int i = 0; i < n; ++i) {
        if (is_strong) *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
        else *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int N;
vector<PI> p;
VI L;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    p.resize(N);
    L.resize(N, INF);

    REP(i, N) {
        cin >> p[i].first >> p[i].second;
    }

    sort(ALL(p), [] (PI lh, PI rh) -> bool { return lh.first == rh.first && lh.second > rh.second || lh.first < rh.first;});

    for (int i = 0; i < N; i++) {
        *lower_bound(ALL(L), p[i].second) = p[i].second;
    }
    int ans = lower_bound(ALL(L), INF) - L.begin();

    cout << ans << endl;

    return 0;
}