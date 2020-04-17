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

const int mod = 1000000007;

struct Box {
    int h, w;
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<Box> box(n);
    REP(i, n) cin >> box.at(i).h >> box.at(i).w;

    sort(ALL(box), [] (const Box lb, const Box rb) {return lb.h == rb.h && lb.w > rb.w || lb.h < rb.h;});

    vector<int> dp(n, INT32_MAX);

    REP(i, n) {
        *lower_bound(ALL(dp), box.at(i).w) = box.at(i).w;
    }

    cout << lower_bound(ALL(dp), INT32_MAX) - dp.begin() << endl;

    return 0;
}