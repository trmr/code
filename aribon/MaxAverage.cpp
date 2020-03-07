#include <bits/stdc++.h>

using namespace std;

struct item {
    int w, v;
};

bool comp(double a, int n, int k, vector<item> S) {
    double sum_y = 0;
    vector<double> Y(n);
    for (int i = 0; i < n; i++) {
        Y[i] = S[i].v - S[i].w * a;
    }

    sort(Y.begin(), Y.end(), greater<int>());

    for (int i = 0; i < k; i++) {
        sum_y += Y[i];
    }

    return sum_y >= 0;
}


int main() {
    int n, k; cin >> n >> k;
    vector<item> S(n);
    for (auto& s:S) {
        cin >> s.w >> s.v;
    }

    double lb = 0;
    double ub = 100;

    for (int i = 0; i < 100; i++) {
        double mid = (lb + ub) / 2;
        if (comp(mid, n, k, S)) lb = mid;
        else ub = mid; 
    }

    cout << fixed;

    cout << setprecision(2) << ub << endl;

    return 0;

}