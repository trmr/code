#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using Field = vector<vector<int>>;
using Graph = vector<vector<int>>;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

void rec(int x, int parent, vector<vector<int>> &v, vector<bool> &done, bool &flag) {
    for (auto child : v.at(x)) {
        if (child == parent) continue;
        if (done.at(child)) flag = false;
        else {
            done.at(child) = true;
            rec(child, x, v, done, flag);
        }
    }
    return;
}




int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>());
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v.at(a).push_back(b);
        v.at(b).push_back(a);
    }

    vector<bool> done(n, false);

    int ans = 0; 

    REP(i, n) {
        if (done.at(i) == false) {

            bool flag = true;
            rec(i, -1, v, done, flag);

            if (flag) ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}