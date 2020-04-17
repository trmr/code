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

bool possible(string _s, string _t, int _i, int _j, int _k) {
    string t = _t;
    string s = _s;
    char tmp;
    tmp = t.at(_i);
    t.at(_i) = t.at(_j);
    t.at(_j) = tmp;

    int cnt = 0;
    for (int i = 0; i < t.size(); i++) {
        if (s.at(i) != t.at(i)) cnt++;
    }

    if (cnt > _k) return false;
    else return true;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    string s; cin >> s;

    string t = s;
    string ans;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((t.at(i) > t.at(j)) && possible(s, t, i, j, k)) {
                if (i < j) {
                    char tmp = t.at(i);
                    t.at(i) = t.at(j);
                    t.at(j) = tmp;
                }
            }
        }
    }

    cout << t << endl;
    
    return 0;
}