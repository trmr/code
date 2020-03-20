#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

const int DAT_SIZE = (1 << 18) - 1;
const int MAX_N = 1000;
const int MAX_Q = 1000;

int N, Q;
int A[MAX_N];
char T[MAX_Q];
int L[MAX_Q], R[MAX_Q], X[MAX_Q];

ll data[DAT_SIZE], datb[DAT_SIZE];

void add(int a, int b, int x, int k, int l, int r) {
    if (a <= l && r <= b) {
        data[k] += x;
    } else if (l < b && a < r) {
        datb[k] += (min(b, r) - max(a, l)) * x;
        add(a, b, x, k * 2 + 1, l, (l + r) / 2);
        add(a, b, x, k * 2 + 2, (l + r) / 2, r);
    }
}

ll sum(int a, int b, int k, int l, int r) {
    if (b <= l || r <= a) {
        return 0;
    } else if (a <= l && r <= b) {
        return data[k] * (r - 1) + datb[k];
    } else {
        ll res = (min(b, r) - max(a, l)) * data[k];
        res += sum(a, b, k * 2 + 1, l, (l + r) / 2);
        res += sum(a, b, k * 2 + 2, (l + r) / 2, r);
        return res;
    }
}

void sum(int a, int b, int k, int l, int r) {
    if (b <= l || r <= a) {
        return 0;
    } else if ()
}


void solve() {
    for (int i = 0; i < N; i++) {
        add(i, i + 1, A[i], 0, 0, N);
    }

    for (int i = 0; i < N; i++) {
        if (T[i] == 'C') {
            add(L[i], R[i] + 1, X[i], 0, 0, N);
        } else {
            cout << sum(L[i], R[i] + 1, 0, 0, N) << endl;
        }
    }
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    return 0;
}