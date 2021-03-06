#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int MAX = 510000;
const int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

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
    COMinit();
    cout << COM(100000, 50000) << endl;

    return 0;
}
