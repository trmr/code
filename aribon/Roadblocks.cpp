#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using P = pair<int, int>;

const int MAX_N = 5;
const int INF = 1000000001;

struct Edge {
    int to, from, cost;
};

int main() {
    int N, R; cin >> N >> R;
    vector<vector<Edge>> G(N, vector<Edge>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            G[i][j].from = i;
            G[i][j].to = j;
            cin >> G[i][j].cost;
        }
    }

    vector<int> dist(MAX_N, INF);
    vector<int> dist2(MAX_N, INF);

    priority_queue<P, vector<P>, greater<P>> que;

    dist[0] = 0;
    que.push(P(0,0));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        int to = p.second, cost = p.first;
        if (dist2[to] < cost) continue;
        for (int i = 0; i < G[to].size(); i++) {
            Edge &e = G[to][i];
            int cost2 = cost + e.cost;
            if (dist[e.to] > cost2) {
                swap(dist[e.to], cost2);
                que.push(P(dist[e.to], e.to));
            }
            if (dist2[e.to] > cost2 && dist[e.to] < cost2) {
            dist2[e.to] = cost2;
            que.push(P(dist2[e.to], e.to));
            }
        }
    }
    cout << dist2[N-1] << endl;

    return 0;
}
