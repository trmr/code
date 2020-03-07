#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll modpow(ll a, ll n, int mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;

        n >>= 1;
    }
    return res;
}

ll gcd (ll a, ll b) {
    if (a%b) return b;
    else return(gcd(b, a%b));
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    ll n, a, b; cin >> n >> a >> b;

    ll c = n / (a + b);
    ll d = n % (a + b);

    ll ans = c * a + min((ll)a, d);

    cout << ans << endl;

    return 0;

}