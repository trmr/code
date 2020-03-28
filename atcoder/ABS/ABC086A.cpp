#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    if ((a % 2) && (b % 2)) {
        cout << "Odd" << endl;
    } else {
        cout << "Even" << endl;
    }
    return 0;
}