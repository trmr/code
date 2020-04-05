#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

vector<int> next_num(int n) {
    vector<int> v;
    if (n == 0) {
        v.push_back(0);
        v.push_back(1);
        return v;
    } else if (n == 9) {
        v.push_back(8);
        v.push_back(9);
        return v;
    } else {
        v.push_back(n - 1);
        v.push_back(n);
        v.push_back(n + 1);
        return v;
    }
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int k; cin >> k;

    priority_queue<ll, vector<ll>, greater<ll>> que;

    for (int i = 1; i < 10; i++) {
        que.push(i);
    }

    for (int i = 0; i < k - 1; i++) {

        ll num = que.top();
        que.pop();
        int least_num = num % 10;
        vector<int> v = next_num(least_num);
        for (auto x:v) {
            que.push(num*10 + x);
        }
    }

    cout << que.top() << endl;



    return 0;
}