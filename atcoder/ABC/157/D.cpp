#include <iostream>
#include <vector>

using namespace std;


const int MAX_N = 100;

vector<int> par(MAX_N);
vector<int> rank(MAX_N);

void init(int n) {
    for (int i = 0; i < n; ++i) {
        par[i] = i;
        rank[i] = 0;
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

    if (rank[x] < rank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    int N, M, K; cin >> N >> M >> K;
    vector<pair<int, int>> F(M);
    vector<pair<int, int>> B(K);

    vector<bool> used(N);

    for (auto f:F) cin >> f.first >> f.second;
    for (auto b:B) cin >> b.first >> b.second;

    init(N);

    for (int i = 0; i < N; i++) {
        int n = N[i];
        int m = 0;

        for (int j = i + 1; j < N; j++) {
            if (!used[j]) m = N[j];
        }

        unite(n, m);



    }

}