#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s; cin >> s;
    int length = s.size() - 1;

    ll total = 0;

    for (int i = 0; i < 1 << length; i++) {
        bitset<10> b(i);

        ll ans = 0;
        string term = s.substr(0, 1);

        for (int i = 0; i < length; i++) {
            if (b.test(i)) {
                ll iterm = stoll(term);
                ans += iterm;
                term = "";
            } 
            term += s.substr(i + 1, 1);
        }
        ll iterm = stoll(term);
        ans += iterm;

        total += ans;

    }

    cout << total << endl;
    
    return 0;
}