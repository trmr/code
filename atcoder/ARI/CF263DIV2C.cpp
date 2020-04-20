#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using Field = vector<vector<int>>;
using Graph = vector<vector<int>>;
using VI = vector<int>;
using VC = vector<char>;
using PI = pair<int, int>;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const int mod = 1000000007;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N; cin >> N;
    vector<int> a(N);
    ll total = 0;
    REP(i, N) {
        cin >> a.at(i);
        total += a.at(i);
    }

    priority_queue<int, vector<int>, greater<int>> que;

    for (auto x:a) que.push(x);

    ll ans = total;

    while(que.size() > 1) {
        int x = que.top();
        ans += x;
        total -= x;
        ans += total;
        que.pop();        
    }

    cout << ans << endl;

    
    return 0;
}