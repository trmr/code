#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> t(n);
    REP(i, n) cin >> t.at(i);
    sort(t.begin(), t.end(), greater<int>());

    vector<int> niku = {0, 0};

    for (int i = 0; i < n; i++) {
        int idx;
        if (niku.at(0) > niku.at(1)) idx = 1;
        else idx = 0;

        niku.at(idx) += t.at(i);
    }

    cout << max(niku.at(0), niku.at(1)) << endl;
    
    return 0;
}