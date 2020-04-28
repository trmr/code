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

const long long INF = 1LL<<60;
const int mod = 1000000007;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

int N, M;
ll S;
vector<ll> C, D;

const int MAX = 2500;

struct Edge {
    ll to, c_money, c_time;
    Edge(ll a, ll b, ll c) {
        c_time = a;
        to = b;
        c_money = c;
    }
};

struct Exchange {
    ll money, time;
};

vector<vector<Edge>> G;
vector<Exchange> V;

void solve() {
    if (S >= MAX) S = MAX;
    vector<vector<ll>> dp(N, vector<ll>(MAX + 1, INF));
    auto c = [] (Edge la, Edge ra) {return la.c_time < ra.c_time;};
    priority_queue<Edge, vector<Edge>, decltype(c)> que(c);

    dp.at(0).at(S) = 0;
    que.push(Edge(0, 0, S));

    while (!que.empty()) {
        auto p = que.top(); que.pop();
        ll time = p.c_time;
        ll to = p.to;
        ll money = p.c_money;
        if (time > dp.at(to).at(money)) continue;

        if (money + V.at(to).money <= MAX) {
            ll nmoney = money + V.at(to).money;
            ll ntime = time + V.at(to).time;
            if (chmin(dp.at(to).at(nmoney), ntime)) {
                que.push(Edge(ntime, to, nmoney));
            }
        }

        for (auto e : G.at(to)) {
            if (money < e.c_money) continue;
            int nto = e.to;
            ll nmoney = money - e.c_money;
            ll ntime = time + e.c_time;
            if (chmin(dp.at(nto).at(nmoney), ntime)) {
                que.push(Edge(ntime, nto, nmoney));
            }
        }
    }
    for (int v = 1; v < N; v++) {
        ll ans = INF;
        for (int i = 0; i <= MAX; i++) {
            chmin(ans, dp.at(v).at(i));
        }
        cout << ans << endl;
    }

}



int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> S;
    G.assign(N, vector<Edge>());
    for (int i = 0; i < M; i++) {
        ll u, v, a, b;
        cin >> u >> v >> a >> b;
        u--; v--;
        G.at(u).push_back(Edge(v, a, b));
        G.at(v).push_back(Edge(u, a, b));
    }
    V.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> V.at(i).money >> V.at(i).time;
    }

    solve();

    return 0;
}