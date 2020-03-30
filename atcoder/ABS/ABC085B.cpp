#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    int tmp;
    set<int> A;
    REP(i, n) {
        cin >> tmp;
        A.insert(tmp);
    }

    cout << A.size() << endl;
    
    return 0;
}