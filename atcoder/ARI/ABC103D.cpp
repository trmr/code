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

struct Island {
    int a, b;
};

const int mod = 1000000007;



int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<Island> ab(m);
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        ab.at(i).a = a;
        ab.at(i).b = b;
    }

    sort(ab.begin(), ab.end(), [] (const Island &x, const Island &y) {return x.b < y.b;});

    int ans = 1;

    int a = ab.at(0).a;
    int b = ab.at(0).b;

    REP(i, m) {
        if (ab.at(i).a < b) continue;
        b = ab.at(i).b;
        ans++;
    }

    cout << ans << endl;

    return 0;
}