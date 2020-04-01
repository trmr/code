#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)
int d, g;
vector<int> p(10);
vector<int> c(10);
int minround = 10000000;

int rec(int x, int round) {
    if (x >= g) return round;

    for (int i = 0; i < d; i++) {
        if (p.at(i) == 0) continue;
        else if (p.at(i) == 1) x += c.at(i);
        p.at(i)--;
        minround = min(minround, rec(x + 100 * (i+1), round + 1));
        p.at(i)++;
    }

    return 10000000;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> d >> g;
    REP(i, d) {
        cin >> p.at(i) >> c.at(i);
    }

    rec(0, 0);
    cout << minround << endl;
    
    return 0;
}