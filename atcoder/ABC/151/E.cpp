#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i, n) for(int (i) = 0; (i) < (n); (i)++)

typedef long long ll;

const ll MOD = 1000000007;
const int NUM_ = 400001;
ll fact[NUM_+1], fact_inv[NUM_+1], inv[NUM_+1];

ll n, k;
ll A[NUM_];

void comb_init() {
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < NUM_; i++) {
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i-1] * inv[i] % MOD;
    }
}

ll comb(ll n_, ll k_) {
    if (n_ < k_) return 0;
    if (n_ < 0 || k_ < 0) return 0;
    return fact[n_] * (fact_inv[k_] * fact_inv[n_ - k_] % MOD) % MOD;
}

int main() {
    cin >> n >> k;
    REP(i, n) cin >> A[i];
    sort(A, A+n);
    ll sum_max = 0, sum_min = 0, ans = 0;
    comb_init();
    REP(i, n) {
        sum_max += A[i] * comb(i, k-1)%MOD;
        sum_min += A[i] * comb(n-i-1, k-1)%MOD;
    }
    ans  = (sum_max - sum_min + MOD) % MOD;
    cout << ans << endl;
}