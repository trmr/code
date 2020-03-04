#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main() {
    ll a, b; cin >> a >> b;

    int L = b - a;
    vector<bool> is_prime(L, true);
    ll sq_b = sqrt(b);
    vector<bool> is_prime_sq(sq_b, true);
    ll ans = 0;

    for (ll i = 2; i <= sq_b; i++) {
        if (is_prime_sq[i]) {
            for (ll j = 2 * i; j < sq_b; j += i) is_prime_sq[j] = false;
            for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) {
                is_prime[j - a] = false;
            }
        }
    }
    for (auto x:is_prime) if (x) ans++;

    cout << ans << endl;

    return 0;

}