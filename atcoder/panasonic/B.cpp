#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ll H, W; cin >> H >> W;
    ll x1, x2, y1, y2;

    if (H == 1 || W == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    if (H % 2 == 1) {
        y1 = floor(H / 2) + 1;
        y2 = floor(H / 2); 
    } else if (H % 2 == 0) {
        y1 = H / 2;
        y2 = H / 2;
    }

    if (W % 2 == 1) {
        x1 = floor(W / 2) + 1;
        x2 = floor(W / 2);
    } else if (W % 2 == 0) {
        x1 = W / 2;
        x2 = W / 2;
    }

    cout << x1 * y1 + x2 * y2 << endl;

    return 0;

}