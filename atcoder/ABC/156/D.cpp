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

ll nCr(int n, int r) {
    ll a = 1;
    ll b = 1;
    
    for (int i = 0; i < r; ++i) {
        a *= (n - i);
        b *= (i + 1);
        a %= MOD;
        b %= MOD;
    }
    return (a * modpow(b, MOD - 2, MOD))%MOD;
}

int main() {
    ll n, a, b; cin >> n >> a >> b;
    ll mpow = modpow(2, n, MOD);
    ll ho = nCr(n, a);


    ll ans = (modpow(2, n, MOD) - 1 + MOD - nCr(n, a)%MOD + MOD - nCr(n, b)%MOD) % MOD;

    cout << ans << endl;

    return 0;
}