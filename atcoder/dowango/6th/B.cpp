#include <iostream>
#include <cmath>

using namespace std;

#define ll long long
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)

ll N;
ll x[10000];
ll mod = 1000000007;

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

ll expect(ll n) {
    if (n > 0) {
        return modinv(n, mod) + expect(n - 1);
    } else {
        return 0;
    }
}

ll fact(ll n) {
    if (n > 0) {
        return n * fact(n - 1) % mod;
    } else {
        return 1;
    }
}

void solve() {
    ll ans = 0;

    rep(i, N - 1) {
        ans += (x[i + 1] - x[i]) * expect(i + 1) % mod;
    }
    ans = ans * fact(N-1) % mod;
    cout << ans << endl;

}


int main () {
    cin >> N;
    rep(i, N) {
        cin >> x[i];
    }

    solve();

    return 0;
}