#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p.at(i).first;
        cin >> p.at(i).second;
    }

    double max_l;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            double l = (p.at(i).first - p.at(j).first) * (p.at(i).first - p.at(j).first) + (p.at(i).second - p.at(j).second) * (p.at(i).second - p.at(j).second);
            max_l = max(max_l, l);

        }
    }

    cout << setprecision(6) << sqrt(max_l) << endl;

    return 0;
}