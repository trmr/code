#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int sum_range(int a, int b) {
    if (a == b) return a;

    return sum_range(a, b - 1) + b;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cout << sum_range(0, 4) << endl;
    cout << sum_range(5, 8) << endl;
    
    return 0;
}