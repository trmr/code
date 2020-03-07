#include<bits/stdc++.h>

using namespace std;

int main() {
    int a, b; cin >> a >> b;

    bool flag = false;

    for (int i = 0; i < 10101; i++) {
        int ca =  i * 0.08;
        int cb =  i * 0.1;
        if ((ca == a) && (cb == b)) {
            cout << i << endl;
            flag = true;
            break;
        }
    }

    if (!flag) cout << -1 << endl;

    return 0;
}