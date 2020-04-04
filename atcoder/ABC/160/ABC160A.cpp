#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s; cin >> s;

    if (s.at(2) == s.at(3) && s.at(4) == s.at(5)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}