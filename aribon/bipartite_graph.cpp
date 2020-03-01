#include <iostream>
#include <vector>
using namespace std;

const int MAX_V = 100;
const int INF = 1000000000;

vector<vector<int>> G(MAX_V, vector<int>(MAX_V, INF));
int V;

int color[MAX_V];

bool dfs(int v, int c) {
    color[v] = c;

    for (int i = 0; i < 2; i++){
        if (color[G[v][i]] == c) return false;
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false; 
    }
    return true;
}

void solve() {
    for (int i = 0; i < V; i++) {
        if (color[i] == 0) {
            if (!dfs(i, 1)) {
                cout << "No" << endl;
                return ;
            }
        }
    }
    cout << "Yes" << endl;
}

int main() {
    cin >> V;
    for (int i = 0; i < V; i++) {
        int edge; cin >> edge;
        for (int j = 0; j < edge; j++) {
            cin >> G[i][j];
        }
    }
    solve();
    return 0;
}