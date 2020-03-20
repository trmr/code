#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;
using ll = long long;

int bit[MAX_N + 1], n;

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add(int i, int x) {
    while (i <= n) {
        bit[i] += x;
        i += i & -i;
    }
}

int n, a[MAX_N];

void solve() {
    ll ans = 0;
    for (int j = 0; j < n; j++) {
        ans += j - sum(a[j]);
        add(a[j], 1);
    }
}

