#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;


int main() {
    ll a, b; cin >> a >> b;

    vector<ll> prime(b);
    vector<bool> is_prime(b, true);

    int p = 0;
    int ans = 0;

    is_prime[0] = is_prime[1] = false;

    for (ll i = 2; i <= b; i++) {
        if (is_prime[i]) {
            if (a <= i) {
                prime[p++] = i;
                ans++;
            }
            for (ll j = 2 * i; j <= b; j += i) is_prime[j] = false;
        }
    }

    cout << ans << endl;

    return 0;

}