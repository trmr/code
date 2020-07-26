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

ll N, W;
vector<pair<ll, ll>> P;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> W;
    P.resize(N + 1);
    REP(i, N) {
        cin >> P[i].first >> P[i].second;
    }

    vector<pair<ll, ll>> A;
    for (int bit = 0; bit < (1 << N / 2); bit++) {
        ll sum_v = 0;
        ll sum_w = 0;
        bitset<100> b(bit);
        for (int i = 0; i < N/2; i++) {
            if (b.test(i)) {
                sum_v += P[i].first;
                sum_w += P[i].second;
            }
        }
        A.push_back(make_pair(sum_w, sum_v));
    }

    vector<pair<ll, ll>> B;
    for (int bit = 0; bit < (1 << (N - N / 2)); bit++) {
        ll sum_v = 0;
        ll sum_w = 0;
        bitset<100> b(bit);
        for (int i = 0; i < N - N/2; i++) {
            if (b.test(i)) {
                sum_v += P[i + N/2].first;
                sum_w += P[i + N/2].second;
            }
        }
        B.push_back(make_pair(sum_w, sum_v));
    }

    sort(B.begin(), B.end(), [](pair<ll, ll> lh, pair<ll, ll> rh) -> bool {return lh.first < rh.first; });

    ll max_v = 0;

    for (int i = 0; i < A.size(); i++) {
        if (W - A[i].first >= 0) {
            auto b_v = (lower_bound(B.begin(), B.end(), make_pair(W-A[i].first, 1ll << 55)) - 1) ->second;
            chmax(max_v, A[i].second + b_v);
        }

    }

    cout << max_v << endl;    

    return 0;
}