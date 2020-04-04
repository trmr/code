#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int x; cin >> x;

    int ans = 0;

    ans += (x/500)*1000;
    x %= 500;
    ans += (x/5)*5;

    cout << ans << endl;

    return 0;
}