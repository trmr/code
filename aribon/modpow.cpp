#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n != 1;
}

int main() {
    int N; cin >> N;

    int x = 3;

    if (is_prime(N)) {cout << "No" << endl; return 0;}

    if (mod_pow(x, N, N) == x) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}