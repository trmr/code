#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from, to, cost;
    bool used;
};

const int INF = 1000000001;

int main() {
    int N, ML, MD; cin >> N >> ML >> MD;
    int num_E = ML + MD;
    vector<Edge> E(num_E);
    for (int i = 0; i < ML; i++) {
        cin >> E[i].from >> E[i].to >> E[i].cost;
        E[i].from--;
        E[i].to--;
    }
    for (int i = ML; i < ML + MD; i++) {
        cin >> E[i].to >> E[i].from >> E[i].cost;
        E[i].from--;
        E[i].to--;
        E[i].cost = -E[i].cost;
    }

    vector<int> d(N, INF);
    d[0] = 0;

    for (int i = 0; i < N; i++) {

        for (int j = 0; j + 1 < N; j++) {
            if (d[j+1] < INF) d[j] = min(d[j], d[j + 1]);
        }

        for (int j = 0; j < num_E; j++) {
            if (d[E[j].from] < INF) {
                d[E[j].to] = min(d[E[j].to], d[E[j].from] + E[j].cost);
            }
        }

    }

    int res = d[N - 1];

    if (d[0] < 0) {
        res = -1;
    } else if (res == INF) {
        res = -2;
    }
    
    cout << res <<endl;

    return 0;
}