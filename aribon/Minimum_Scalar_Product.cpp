#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> V1(n);
    vector<int> V2(n);

    for (auto& x:V1) cin >> x;
    for (auto& x:V2) cin >> x;

    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end(), greater<int>());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += V1[i] * V2[i];
    }
    cout << ans << endl;

    return 0;
}
