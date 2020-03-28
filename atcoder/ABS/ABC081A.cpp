#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    vector<char> s(3);
    cin >> s.at(0) >> s.at(1) >> s.at(2);
    int ans = 0;
    for (auto &x:s) {
        if (x == '1') ans++; 
    }
    cout << ans << endl;
    return 0;
}