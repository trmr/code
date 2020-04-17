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

struct Robo {
    ll x, l;
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<Robo> robo(n);
    for (int i = 0; i < n; i++) {
        ll x, l;
        cin >> x >> l;
        robo.at(i).x = x;
        robo.at(i).l = l;
    }

    sort(robo.begin(), robo.end(), [](auto const &lhs, auto const &rhs) {return lhs.x+lhs.l < rhs.x+rhs.l;});

    ll used = 1;
    ll pt = robo.at(0).x + robo.at(0).l;
    for (int i = 1; i < n; i++) {
        ll x, l;
        x = robo.at(i).x;
        l = robo.at(i).l;
        if (pt <=  x - l) {
            used++;
            pt = x + l;
        }
    }

    cout << used << endl;

    return 0;
}