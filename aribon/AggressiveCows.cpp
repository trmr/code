#include <bits/stdc++.h>

using namespace std;

bool comp(int a, int n, int m, vector<int> X) {
    int pos = 0;
    for (int i = 0; i < m; i++) {
        int next = pos + 1;
        while (next < m && X[next] - X[pos] < a) {
            next++;
        }
        if (next == n) return false;
        pos = next;
    }
    return true;
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> X(n);
    for (auto& x:X) cin >> x;

    sort(X.begin(), X.end());

    int lb = 0;
    int ub = *(max_element(X.begin(), X.end()));

    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (comp(mid, n, m, X)) lb = mid;
        else ub = mid;
    }

    cout << lb << endl;

    return 0;

}