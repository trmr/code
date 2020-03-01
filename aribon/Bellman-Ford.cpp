#include <iostream>
#include <vector>

using namespace std;
const int INF = 1000000000;

struct edge {
    int from, to;
    int cost;
}

int main() {
    int V, E; cin >> V >> E;
    int s; cin >> s;
    vector<edge> es(E);
    int from_, to_, cost_;
    for (int i = 0; i < E; i++) {
        cin >> from_ >> to_ >> cost_;
        edge _e = {from_, to_, cost_};
        es.push_back(_e);
    }

    int d[E];
    for (int i = 0; i < V; i++) d[i] = INF;
    d[s] = 0;
    while (true) {
        bool update = false;
        for (int i = 0; i < E; i++) {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if (!update) break;
    }

    return 0;
}