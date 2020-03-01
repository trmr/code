#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from, to, cost;
    bool used;
};

const int MAX_N = 100;

vector<int> par(MAX_N);
vector<int> rank(MAX_N);

void init(int n) {
    for (int i = 0; i < n; ++i) {
        par[i] = i;
        ::rank[i] = 0;
    }
}

int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (::rank[x] < ::rank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (::rank[x] == ::rank[y]) ::rank[x]++;
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

bool comp(const Edge& e1, const Edge& e2) {
    return e1.cost < e2.cost;
}

int main() {
    int num_X, num_Y, num_V, num_E; cin >> num_X >> num_Y >> num_E;
    num_V = num_X + num_Y;
    vector<Edge> E(num_E);
    for (auto& x:E) {
        cin >> x.from >> x.to >> x.cost;
        x.to += num_X;
        x.cost = -x.cost;
    }

    sort(E.begin(), E.end(), comp);

    init(num_V);
    int res = 0;
    for (int i = 0; i < num_E; i++) {
        Edge e = E[i];
        if (!same(e.from, e.to)) {
            unite(e.from, e.to);
            res += e.cost;
        }
    }
    cout << 10000 * (num_V) + res << endl;
    return 0;
    
}