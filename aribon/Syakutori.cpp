#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, s; cin >> n >> s;
    vector<int> A(n);
    for (auto& a:A) cin >> a;

    int ans = n + 1;

    int st = 0, lt = 0, sum = 0;

    for (;;) {
        while (lt < n && sum < s) {
            sum += A[lt++];
        }
        if (sum < s) break;
        ans = min(ans, lt - st);
        sum -= A[st++];
    }

    if (ans > n) {
        ans = 0;
    }

    cout << ans << endl;

    return 0;
}