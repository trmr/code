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

string s, t;
vector<vector<int>> dp(3010, vector<int>(3010, 0));
vector<vector<pair<int, int>>> prev_ij(3010, vector<pair<int,int>>(3010, pair<int, int>()));


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> s >> t;
    int lens = s.size();
    int lent = t.size();

    dp.at(0).at(0) = 0;

    for (int i = 0; i < lens; i++) {
        for (int j = 0; j < lent; j++) {
            if (s.at(i) == t.at(j)) {
                chmax(dp.at(i + 1).at(j + 1), dp.at(i).at(j) + 1);
                prev_ij.at(i + 1).at(j + 1) = make_pair(i,j);
            }
            if (dp.at(i + 1).at(j + 1) < dp.at(i + 1).at(j)) {
                chmax(dp.at(i + 1).at(j + 1), dp.at(i + 1).at(j));
                prev_ij.at(i + 1).at(j + 1) = make_pair(i + 1, j);
            }
            if (dp.at(i + 1).at(j + 1) < dp.at(i).at(j + 1)) {
                chmax(dp.at(i + 1).at(j + 1), dp.at(i).at(j + 1));
                prev_ij.at(i + 1).at(j + 1) = make_pair(i, j + 1);
            }
        }
    }


    int i = lens;
    int j = lent;
    string ans;
    while(i > 0 && j > 0) {
        if (dp.at(i).at(j) == dp.at(i - 1).at(j)) i--;
        else if (dp.at(i).at(j) == dp.at(i).at(j - 1)) j--;
        else {
            i--; j--;
            ans = s.at(i) + ans;
        }
    }

    cout << ans << endl;

    return 0;
}