#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

bool check(int x, int a, int b) {
    int sum = 0;
    int digit = 10000;
    for (int i = 4; i >= 0; i--) {
        sum += x/digit;
        x = x % digit;
        digit = digit / 10;
    }
    if (a <= sum && sum <= b) return true;
    else return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, a, b;cin >> n >> a >> b;

    int sum = 0;

    for (int i = 1; i < n + 1; i++) {
        if (check(i, a, b)) sum += i;
    }

    cout << sum << endl;

    return 0;
}