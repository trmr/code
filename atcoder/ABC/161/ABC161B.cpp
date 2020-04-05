#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;

    priority_queue<int> que;

    int total_vote = 0;

    REP(i, n) {
        int a; cin >> a;
        que.push(a);
        total_vote += a;
    }

    REP(i, m - 1) {
        que.pop();
    }

    int x = que.top();

    if ((double)total_vote / (4 * m) <= x) {
        cout << "Yes" << endl;
    } else cout << "No" << endl;

    return 0;
}