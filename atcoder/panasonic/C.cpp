#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll a, b, c;cin >> a >> b >> c;
    if (((c - a - b) > 0) && (((c - a - b) * (c - a - b) - 4 * a * b) > 0)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}