#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) {}

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool isSame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y){
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }
};

using P = pair<int, int>;

int main() {
    int N, M, K; cin >> N >> M >> K;
    vector<set<int>> F(N);
    vector<set<int>> B(N);
    UnionFind uf(N);

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--, b--;
        F[a].insert(b);
        F[b].insert(a);
        uf.unite(a, b);
    }
    for (int i = 0; i < K; i++) {
        int c, d; cin >> c >> d; c--, d--;
        if (!uf.isSame(c, d)) continue;
        B[c].insert(d);
        B[d].insert(c);
    }

    for (int i = 0; i < N; i++) {
        int mem = uf.size(i) - 1;
        mem -= F[i].size();
        mem -= B[i].size();
        cout << mem << " ";
    }
    cout << endl;

    return 0;

}
