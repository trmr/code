#include <iostream>
#include <vector>
using namespace std;
using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;
using ll = long long;

int N, M;
Graph G;
vector<int> us, vs;

bool rec(int v, int p, int target, ll &path) {
    if (v == target) {
        path = 0;
        return true;
    }
    for (auto e : G[v]) {
        if (e.first == p) continue;
        if (rec(e.first, v, target, path)) {
            path |= (1LL << e.second);
            return true;
        }
    }
    return false;
}

ll solve() {
    vector<ll> paths(M, 0);
    for (int i = 0; i < M; ++i) rec(us[i], -1, vs[i], paths[i]);
    ll res = 0;
    for (ll bit = 0; bit < (1<<M); ++bit) {
        ll val = 0; 
        for (int i = 0; i < M; ++i) if (bit & (1LL<<i)) val |= paths[i];
        ll remnum = N - 1 - __builtin_popcountl(val);
        if (__builtin_popcountl(bit) % 2 == 0) res += 1LL << remnum;
        else res -= 1LL<<remnum;
    }
    return res;
}

int main() {
    cin >> N;
    G.assign(N, vector<Edge>());
    for (int i = 0; i < N-1; ++i) {
        int x, y; cin >> x >> y; --x, --y;
        G[x].emplace_back(y, i);
        G[y].emplace_back(x, i);
    }
    cin >> M;
    us.resize(M), vs.resize(M);
    for (int i = 0; i < M; ++i) {
        cin >> us[i] >> vs[i];
        -- us[i], --vs[i];
    }
    cout << solve() <<endl;
}