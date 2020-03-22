#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    double L; cin >> L;

    double threeL = L / 3;

    double long volume = threeL * threeL * threeL;

    cout << fixed << setprecision(7) << volume << endl;

    return 0;
}