#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using Field = vector<vector<int>>;
using Graph = vector<vector<int>>;
using VI = vector<int>;
using VC = vector<char>;
using PI = pair<int, int>;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const int mod = 1000000007;

static const int MAX_V = 200;
int V, E;
vector<vector<int>> G(MAX_V,vector<int>());
vector<int> match(MAX_V);
vector<int> used(MAX_V);

void add_edge(int u, int v) {
    G.at(u).push_back(v);
    G.at(v).push_back(u);
}

bool dfs(int v) {
    if (G.at(v).empty()) return false;

    used.at(v) = true;
    for (int i = 0; i < G.at(v).size(); i++) {
        int u = G.at(v).at(i);
        int w = match.at(u);
        if (w < 0 || (!used.at(w) && dfs(w))) {
            match.at(v) = u;
            match.at(u) = v;
            return true;
        }

    }
    return false;
}

int biparticle_matching() {
    int res = 0;
    fill(match.begin(), match.end(), -1);
    for (int v = 0; v < V; v++) {
        if (match.at(v) < 0) {
            fill(ALL(used), 0);
            if (dfs(v)) res++;
        }
    }
    return res;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int N; cin >> N;
    vector<pair<int, int>> R(N);
    vector<pair<int, int>> B(N);
    REP(i, N) cin >> R.at(i).first >> R.at(i).second;
    REP(i, N) cin >> B.at(i).first >> B.at(i).second;

    V = 2 * N;

    REP(i, N) {
        REP(j, N) {
            if (R.at(i).first < B.at(j).first && R.at(i).second < B.at(j).second) {
                add_edge(i, j + N);
            }
        }
    }

    int ans = biparticle_matching();

    cout << ans << endl;


    return 0;
}