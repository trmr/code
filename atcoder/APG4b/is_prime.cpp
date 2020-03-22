#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

bool has_divisor(int N, int i) {
    if (i == N) return false;

    if (N % i == 0) return true;
    
    return has_divisor(N, i + 1);
}

bool is_prime(int N) {
    if (N == 1) return false;
    if (N == 2) return true;

    return !has_divisor(N, 2);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cout << is_prime(1) << endl;  // 0
    cout << is_prime(2) << endl;  // 1
    cout << is_prime(12) << endl; // 0
    cout << is_prime(13) << endl; // 1
    cout << is_prime(57) << endl; // 0
    
    return 0;
}