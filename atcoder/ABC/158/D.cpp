#include <bits/stdc++.h>

using namespace std;

struct in {
    int t, f;
    string c;
};

int main() {
    string s; cin >> s;
    int q; cin >> q;
    deque<char> S;
    for (auto x:s) S.push_back(x);

    int sum_t = 0;
    for(int i = 0; i < q; i++) {
        int t, f;
        char c;
        cin >> t;
        if (t == 2) {
            cin >> f >> c;
        }
 
        if (t == 1) sum_t++;
        else if ((sum_t % 2) == 0) {
            if (f == 1) S.push_front(c);
            else S.push_back(c);
        } else {
            if (f == 1) S.push_back(c);
            else S.push_front(c);
        }
    }

    if ((sum_t % 2) == 1) reverse(S.begin(), S.end());
    for (auto& x:S) cout << x;
    cout << endl;
    
    return 0;
}