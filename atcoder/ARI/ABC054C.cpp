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


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    Graph G(n, vector<int>());

    REP(i, m) {
        int a, b; cin >> a >> b;
        a--, b--;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    VI np;
    REP(i, n) np.push_back(i);

    sort(np.begin(), np.end());

    int ans = 0;

    do {
        bool flag = true;
        if (np.at(0) != 0) continue;
        REP(i, n-1) {
            int from = np.at(i);
            int to = np.at(i + 1);
            if (find(G.at(from).begin(), G.at(from).end(), to) == G.at(from).end()){
                flag = false;
                break;
            }
        }
        if (flag) ans++;

    }while(next_permutation(np.begin(), np.end()));

    cout << ans << endl;
    
    return 0;
}