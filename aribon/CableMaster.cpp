#include <bits/stdc++.h>

using namespace std;

bool comp(double x, int n, int k, vector<double> L) {
    int num = 0;
    for (int i = 0; i < n; i++) {
        num += (int)(L[i] / x);
    }
    return num >= k;
}

int main() {
    int n, k; cin >> n >> k;
    vector<double> L(n);
    for (auto& l:L) cin >> l;

    double ub = *(max_element(L.begin(), L.end()));
    double lb = 0;

    for (int i = 0; i < 100; i++) {
        double mid = (lb + ub) / 2;
        if (comp(mid, n, k, L)) lb = mid;
        else ub = mid;
    }

    cout << fixed;
    cout << setprecision(2) << ub << endl;

    return 0;

}