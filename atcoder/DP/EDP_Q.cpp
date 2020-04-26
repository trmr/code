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

template <typename T>
struct SegTree {
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat;
    SegTree(int n_): n(), dat(n_ * 4, 0) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }

    void update(int i, T x) {
        i += n - 1;
        dat.at(i) = x;
        while (i > 0) {
            i = (i - 1) / 2;
            dat.at(i) = max(dat.at(i * 2 + 1), dat.at(i * 2 + 2));
        }
    }

    T query(int a, int b) {return query_sub(a, b, 0, 0, n);}
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return 0;
        else if (a <= l && r <= b) return dat.at(k);
        else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return max(vl, vr);
        }
    }

};


int N;
vector<ll> H;
vector<ll> A;

SegTree<ll> dp(1 << 18);


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    A.resize(N + 1);
    H.resize(N + 1);

    REP(i, N) cin >> H.at(i);
    REP(i, N) cin >> A.at(i);

    REP(i, N) {
        ll opt = dp.query(0, H.at(i)) + A.at(i);
        dp.update(H.at(i), opt);
    }

    cout << dp.query(0, N+1) << endl;

    return 0;
}