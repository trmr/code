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
    int k; cin >> k;
    ll ans = 0;
    for (int a = 1; a < k + 1; a++) {
        for (int b = 1; b < k + 1; b++) {
            for (int c = 1; c < k + 1; c++) {
                ans += gcd(a, gcd(b, c));
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}