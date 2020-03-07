#include <bits/stdc++.h>

using namespace std;

int main() {
    int p; cin >> p;
    vector<int> A(p);
    for (auto& a:A) cin >> a;

    set<int> all;
    for (auto& a:A) all.insert(a);
    int n = all.size();

    int st = 0, lt = 0, num = 0;
    map<int, int> count;
    int res = p;

    for(;;) {
        while (lt < p && num < n) {
            if (count[A[lt++]]++ == 0) {
                num++;
            } 
        }
        if (num < n) break;
        res = min(res, lt - st);
        if (--count[A[st++]] == 0) {
            num--;
        }
    }

    cout << res << endl;

    return 0;
}