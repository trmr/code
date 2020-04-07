#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using Field = vector<vector<int>>;
using Graph = vector<vector<int>>;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
vector<vector<char>> a(10, vector<char>(10));

void rec(int i, int j, vector<vector<char>> &a2) {
    if (i < 0 || 9 < i || j < 0 || 9 < j) return;
    if (a2.at(i).at(j) == 'x') return;

    a2.at(i).at(j) = 'x';
    REP(x, 4) {
        rec(i + dx.at(x), j + dy.at(x), a2);
    }
    return;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    REP(i, 10) {
        string line; cin >> line;
        REP(j, 10) {
            a.at(i).at(j) = line.at(j);
        }
    }

    bool flag = false;
    REP(i, 10) {
        REP(j, 10) {
            if (a.at(i).at(j) == 'o') continue;
            vector<vector<char>> a2 = a;
            a2.at(i).at(j) = 'o';
            rec(i, j, a2);
            flag = true;
            REP(x, 10) {
                REP(y, 10) {
                    if (a2.at(x).at(y) == 'o') {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) break;
        }
        if (flag) break;
    }

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}