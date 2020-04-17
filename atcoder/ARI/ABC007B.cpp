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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s; cin >> s;

    if (s.size() == 1 && s.at(0) == 'a') cout << -1 << endl;
    else cout << 'a' << endl;

    return 0;
}