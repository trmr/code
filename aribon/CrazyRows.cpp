#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

const int MAX_N = 40;

int N;
int M[MAX_N][MAX_N];

int a[MAX_N];

void solve() {
    int res = 0;
    for (int i = 0; i < N; i++) {
        a[i] = -1;
        for (int j = 0; j < N; j++) {
            if (M[i][j] == i) a[i] = j;
        }
    }

    for (int i = 0; i < N; i++) {
        int pos = -1;
        for (int j = i; j < N: j++) {
            if (a[j] <= i) {
                pos = j;
                break;
            }
        }

        
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    return 0;
}