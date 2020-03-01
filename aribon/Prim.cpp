#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000001;

struct Edge {
    int from, to, cost;
    bool used;
};


int main() {
    int N; cin >> N;
    vector<Edge> E(N);
    vector<int> mincost(N);

    for (int i = 0; i < N; i++) {
        mincost[i] = INF;
        E[i].used = false;
    }

    mincost[0] = 0;
    int ans = 0;

    while (true) {
        int v = -1;

        for (int i = 0; i < N; i++) {
            if (!E[i].used && (v == -1 || mincost[i] < mincost[v])) v = i;
        }

        if (v == -1) break;

        E[i].used = true;
        ans += mincost[v];

        for (int i = 0; i < N; i++) {
            if (v == E[i].from && i == E[i].to) {
                mincost[i] = min(mincost[i], E[i].cost);
            }
        }

    }

    cout << ans << end;


    return 0;

}