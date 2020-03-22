#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    vector<int> A(3);
    REP(i, 3) cin >> A[i];

    sort(A.begin(), A.end());

    cout << A.at(2) - A.at(0) << endl;

    return 0;
}