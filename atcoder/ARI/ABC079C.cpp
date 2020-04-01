#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

vector<int> abcd(4);
vector<char> op(4);

bool flag = false;

int rec(int x, int round) {
    if (round == 4) {
        if (x == 7) {
            return 1;
        }
        return 0;
    } 
    if (flag) return 0;

    op.at(round - 1) = '+';
    if (rec(x + abcd.at(round), round + 1)) {
        cout << abcd.at(0) << op.at(0) << abcd.at(1) << op.at(1) << abcd.at(2) << op.at(2) << abcd.at(3) << "=7" << endl;
        flag = true;
        return 0;
    }
    op.at(round - 1) = '-';
    if (rec(x - abcd.at(round), round + 1)) {
        cout << abcd.at(0) << op.at(0) << abcd.at(1) << op.at(1) << abcd.at(2) << op.at(2) << abcd.at(3) << "=7" << endl;
        flag = true;
        return 0;
    }

    return 0;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int x; cin >> x;
    abcd.at(3) = x %10;
    abcd.at(2) = (x / 10) % 10;
    abcd.at(1) = (x / 100) % 10;
    abcd.at(0) = (x / 1000) % 10;

    rec(abcd.at(0), 1);

    return 0;
}