#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

ll gcd(ll a, ll b) {
    if (a < b) return gcd(b, a);
    ll r;
    while ((r=a%b)) {
        a = b;
        b = r;
    }
    return b;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;
    ll ans = 0;
    if (n % k == 0) ans = 0;
    else {
        ll g = n % k;
        ans = min(g, abs(k - g));
    }

    cout << ans << endl;

    return 0;
}