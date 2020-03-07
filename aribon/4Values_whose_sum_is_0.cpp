#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> A(n), B(n), C(n), D(n);
    for (auto& a:A) cin >> a;
    for (auto& a:B) cin >> a;
    for (auto& a:C) cin >> a;
    for (auto& a:D) cin >> a;

    vector<int> AB;

    vector<int> CD;

    for (auto& a:A) {
        for (auto& b:B) {
            AB.push_back(a + b);
        }
    }
    
    for (auto& c:C) {
        for (auto& d:D) {
            CD.push_back(c + d);
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    int ans = 0;


    for (auto& x:AB) {

        ans += upper_bound(CD.begin(), CD.end(), x) - lower_bound(CD.begin(), CD.end(), x);
        
    }

    cout << ans << endl;

    return 0;
}