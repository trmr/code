#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using Field = vector<vector<int>>;
using Graph = vector<vector<int>>;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

void rec(int v, const Graph &G, vector<bool> &seen, vector<int> &order) {
    seen.at(v) = true;
    for (auto next : G.at(v)) {
        if (seen.at(next)) continue;
        rec(next, G, seen, order);
    }
    order.push_back(v);
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    Graph G(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G.at(a).push_back(b);
    }

    vector<bool> seen(n, 0);
    vector<int> order;

    for (int v = 0; v < n; v++) {
        if (seen.at(v)) continue;
        rec(v, G, seen, order);
    }
    reverse(ALL(order));

    for (auto v : order) cout << v << " -> ";
    cout << endl;
    
    return 0;
}