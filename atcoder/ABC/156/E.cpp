#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int MAX = 510000;
const int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

ll modpow(ll a, ll n, int mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;

        n >>= 1;
    }
    return res;
}

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i=2; i<MAX; i++) {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(int n, int k) {
    if(n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

ll HCOM(int n, int k) {
    return (n == 0 && k == 0) ? 1 : COM(n+k-1, k);
}


int main() {
    ll n, k;
    cin >> n >> k;

    COMinit();

    ll x = 0;

    if (n < k) {
        x = n;
    } else {
        x = k;
    }

    ll ans = 0;
    
    for (ll i = 0; i <= x; ++i) {
        ll res = 0;
        res += COM(n, i);
        res %= MOD;

        res *= HCOM(n - i, i);
        res %= MOD;

        ans += res;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}