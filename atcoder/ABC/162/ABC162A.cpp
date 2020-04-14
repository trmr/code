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

    bool flag = false;

    do {
        if (n%10 == 7) {
            flag = true;
            break;
        }
    } while (n = n / 10);

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}