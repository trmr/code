#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int x, y, a, b, c; cin >> x >> y >> a >> b >> c;
    vector<int> p(a);
    vector<int> q(b);
    vector<int> r(c);

    REP(i, a) cin >> p.at(i);
    REP(i, b) cin >> q.at(i);
    REP(i, c) cin >> r.at(i);


    sort(p.begin(), p.end(), greater<int>());
    sort(q.begin(), q.end(), greater<int>());
    sort(r.begin(), r.end(), greater<int>());


    priority_queue<int> que;


    REP(i, x) {
        que.push(p.at(i));
    }
    REP(i, y) {
        que.push(q.at(i));
    }
    REP(i, c) {
        que.push(r.at(i));
    }

    int ans = 0;

    REP(i, x+y) {
        ans += que.top();
        que.pop();
    }

    cout << ans << endl;


    return 0;
}