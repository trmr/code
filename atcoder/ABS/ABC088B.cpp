#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    priority_queue<int> a;
    int tmp;
    REP(i, n) {
        cin >> tmp;
        a.push(tmp);
    }

    int sum_a = 0;
    int sum_b = 0;

    int cnt = 0;
    while (!a.empty()) {
        if (cnt%2) {
            sum_b += a.top();
        } else {
            sum_a += a.top();
        }
        a.pop();
        cnt++;
    }

    cout << abs(sum_a - sum_b) << endl;

    return 0;
}