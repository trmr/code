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

struct Cups {
    vector<vector<int>> S;
    int t, prev_from, prev_to;
    Cups(vector<vector<int>> _S, int _t, int _from, int _to)
    :S(_S), t(_t), prev_from(_from), prev_to(_to){}
};


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;cin >> n >>m;
    vector<vector<int>> S(3, vector<int>());
    REP(i, 3) {
        int SN; cin >> SN;
        REP(j, SN) {
            int e; cin >> e;
            S.at(i).push_back(e - 1);
        }
        sort(S.at(i).begin(), S.at(i).end(), greater<int>());
    }

    queue<Cups> que;
    que.push(Cups(S, 0, -1, -1));

    int ans = -1;
    while (!que.empty()) {
        Cups c = que.front(); que.pop();
        vector<vector<int>> S = c.S;
        int t = c.t, prev_from = c.prev_from, prev_to = c.prev_to;

        if (t > m) continue;

        if (S.at(0).size() == n || S.at(2).size() == n) {
            ans = t;
            break;
        }

        REP(from, 3) {
            REP(to, 3) {
                if (abs(from - to) != 1 || ((to == prev_from) && (from == prev_to)) || S.at(from).empty() || (!S.at(to).empty() && (S.at(from).at(0) < S.at(to).at(0)))) continue;

                vector<VI> _S = S;
                _S.at(to).push_back(_S.at(from).at(0));
                _S.at(from).erase(_S.at(from).begin());
                sort(_S.at(to).begin(), _S.at(to).end(), greater<int>());

                que.push(Cups(_S, t + 1, from, to));


            }
        }

    }

    cout << ans << endl;

    
    return 0;
}