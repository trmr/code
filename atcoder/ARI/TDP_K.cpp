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

ll N;
vector<pair<ll, ll>> P;
vector<ll> L;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    P.resize(N);
    L.resize(N, INF);
    REP(i, N) {
        ll x, r;
        cin >> x >> r;
        P[i].first = x - r;
        P[i].second = x + r;
    }

    sort(ALL(P), [] (pair<ll, ll> lh, pair<ll, ll> rh) -> bool {return lh.first == rh.first && lh.second > rh.second || lh.first > rh.first;});

    for (int i = 0; i < N; i++) {
        *lower_bound(ALL(L), P[i].second) = P[i].second;
    }

    ll ans = lower_bound(ALL(L), INF) - L.begin();

    cout << ans << endl;

    return 0;
}