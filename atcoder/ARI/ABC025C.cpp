#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Field = vector<vector<ll>>;
using Graph = vector<vector<ll>>;
using VI = vector<int>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VC = vector<char>;
using PI = pair<int, int>;

#define FOR(i, s, n) for (int i = s; i < (n); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const long long INF = 1LL<<60;
const int MOD = 1000000007;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

vector<vector<int>> b(3, VI(3));
vector<vector<int>> c(3, VI(3));
vector<vector<int>> M(3, VI(3));

int calc() {
    int point = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (M[i][j] == M[i+1][j]) {
                point += b[i][j];
            }
            
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if (M[i][j] == M[i][j+1]) {
                point += c[i][j];
            }
            
        }
    }
    return point;

}

int dfs(int turn) {
    if (turn == 9) return calc();

    if (turn % 2 == 0) {
        int maxpoint = -1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (M[i][j] == 0) {
                    M[i][j] = 1;
                    maxpoint = max(maxpoint, dfs(turn + 1));
                    M[i][j] = 0;
                }
            }
        }
        return maxpoint;
    } else {
        int minpoint = 1 << 30;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (M[i][j] == 0) {
                    M[i][j] = -1;
                    minpoint = min(minpoint, dfs(turn + 1));
                    M[i][j] = 0;
                }
            }
        }
        return minpoint;
    }

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 2; i++) {
        cin >> b[i][0] >> b[i][1] >> b[i][2];
    }
    for (int i = 0; i < 3; i++) {
        cin >> c[i][0] >> c[i][1];
    }

    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += b[i][j];
            sum += c[i][j];
        }
    }

    int point = dfs(0);

    cout << point << endl;
    cout << sum - point << endl;



    return 0;
}