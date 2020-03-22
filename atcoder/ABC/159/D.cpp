#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

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

int output(map<int, int> count, int key) {
    count.at(key)--;
    int sum = 0;
    for (auto &x:count) {
        sum += COM(x.second, 2);
    }
    return sum;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N; cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A.at(i);

    COMinit();

    set<int> S(A.begin(), A.end());

    map<int, int> count;

    for (auto &x: S) {
        int c = std::count(A.begin() , A.end(), x);
        count.insert(make_pair(x, c));
    }

    REP(i, A.size()) {
        int key = A.at(i);
        cout << output(count, key) << endl;
    }

    return 0;
}