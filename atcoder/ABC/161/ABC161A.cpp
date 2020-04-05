#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int x, y, z; cin >> x >> y >> z;

    swap(x, y);
    swap(x, z);

    cout << x << " " << y << " " << z << endl;
    
    return 0;
}