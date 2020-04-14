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
    vector<char> S(n);
    VI R(n);
    VI G(n);
    VI B(n);

    vector<char> color(3);

    ll ans = 0;

    int max_r = 0, max_g = 0, max_b = 0;

    REP(i, n) {
        cin >> S.at(i);
        if (S.at(i) == 'R') max_r++;
        else if (S.at(i) == 'G') max_g++;
        else if (S.at(i) == 'B') max_b++;
    }
    int num_r = 0, num_g = 0, num_b = 0;

    REP(i, n) {
        if (S.at(i) == 'R') num_r++;
        else if (S.at(i) == 'G') num_g++;
        else if (S.at(i) == 'B') num_b++;

        R.at(i) = max_r - num_r;
        G.at(i) = max_g - num_g;
        B.at(i) = max_b - num_b;

    }


    for (int i = 0; i < n-2; i++) {
        color.at(0) = S.at(i); 
        for (int j = i + 1; j < n-1; j++) {
            if (color.at(0) == S.at(j)) continue;
            color.at(1) = S.at(j);

            if ((color.at(0) == 'R' && color.at(1) == 'G') || (color.at(0) == 'G' && color.at(1) == 'R')) color.at(2) = 'B';
            else if ((color.at(0) == 'B' && color.at(1) == 'G') || (color.at(0) == 'G' && color.at(1) == 'B')) color.at(2) = 'R';
            else if ((color.at(0) == 'B' && color.at(1) == 'R') || (color.at(0) == 'R' && color.at(1) == 'B')) color.at(2) = 'G';

            if (color.at(2) == 'R') {
                ans += R.at(j);
                if ((j + j - i < n) && (S.at(j + j - i) == color.at(2))) ans--;
            }else if (color.at(2) == 'G') {
                ans += G.at(j);
                if ((j + j - i < n) && (S.at(j + j - i) == color.at(2))) ans--;
            }else if (color.at(2) == 'B') {
                ans += B.at(j);
                if ((j + j - i < n) && (S.at(j + j - i) == color.at(2))) ans--;
            }
        }
    }

    cout << ans << endl;

    return 0;
}