
const int MAX_V = 100;

int cost[MAX_V][MAX_V];
int V;

void warshall_floyd() {
    for (int k = 0; k < V; k++)
    for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++) {
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
    }
}
