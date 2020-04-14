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


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    int k; cin >> k;
    vector<int> c(n);
    REP(i, n) {
        cin >> c.at(i);
    }

    set<int> s;

    sort(c.begin(), c.end());

    do {
        string str;
        REP(i, k) {
            str += to_string(c.at(i));
        }
        int value = stoi(str);
        s.insert(value);

    } while (next_permutation(ALL(c)));

    cout << s.size() << endl;
    
    return 0;
}