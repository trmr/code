#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

struct str {
    int t, x, y;
};

bool check (int difft, int diffx, int diffy) {
    if (difft < diffx + diffy) return false;
    if ((difft % 2) != ((diffx + diffy)%2)) return false;
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<str> P(n+1);
    P.at(0).t = 0; P.at(0).x = 0; P.at(0).y = 0; 
    for (int i = 1; i < n + 1; i++) {
        cin >> P.at(i).t >> P.at(i).x >> P.at(i).y;
    }

    bool flag = true;

    for (int i = 1; i < n + 1; i++) {
        int difft = P.at(i).t - P.at(i - 1).t;
        int diffx = P.at(i).x - P.at(i - 1).x;
        int diffy = P.at(i).y - P.at(i - 1).y;
        if (!check(difft, abs(diffx), abs(diffy))) {
            flag = false;
        }
    }

    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}