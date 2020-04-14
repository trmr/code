#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using Field = vector<vector<int>>;
using Graph = vector<vector<int>>;
using VI = vector<int>;
using VC = vector<char>;
using PI = pair<int, int>;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const int mod = 1000000007;

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

vector<long> divisor(int n) {
    vector<long> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    return res;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k; cin >> n >> k;

    vector<ll> X(100100, 0);

    int ans = 0;

    for (int i = k; i > 0; i--) {
        ll num = ((modpow(k/i, n, mod) - X.at(i)) % mod + mod) % mod;
        ans = (ans + num * i + mod) % mod;
        vector<long> d = divisor(i);
        for (auto &it:d) X.at(it) = (X.at(it) + num + mod) % mod;
    }
    
    cout << ans << endl;

    return 0;
}