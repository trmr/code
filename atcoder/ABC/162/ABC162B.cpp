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


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    ll ans = 0;

    for (int i = 1; i < n + 1; i++) {
        if ((i % 3) && (i % 5)) ans += i;
    }

    cout << ans << endl;

    return 0;
}