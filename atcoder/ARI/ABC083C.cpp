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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll X, Y; cin >> X >> Y;

    ll a = X;
    ll ans = 0;

    while (a <= Y) {
        ans++;
        a <<= 1;
    }

    cout << ans << endl;
    
    return 0;
}