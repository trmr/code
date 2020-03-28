#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int cnt = 0;
vector<int> cost = {500, 100, 50};
vector<int> coin;
int X;

int rec(int value, int sum) {
    if (sum == X) {
        cnt++;
        return 1;
    } else if (sum > X) {
        return 1;
    }

    if (value == 3) {
        return 0;
    }

    REP(i, coin.at(value) + 1) {
        if (rec(value + 1, sum + (cost.at(value) * i))) {
            return 0;
        }
    }

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int A, B, C;
    cin >> A >> B >> C >> X;

    REP(i, A+1) {
        REP(j, B+1) {
            REP(k, C+1) {
                if ((i * 500 + j * 100 + k * 50) == X) cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}