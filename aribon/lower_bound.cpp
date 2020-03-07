#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> A(n);
    for (auto& a:A) cin >> a;

    auto ptr = lower_bound(A.begin(), A.end(), k);

    cout << ptr - A.begin() << endl;

    return 0;
}