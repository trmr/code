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
    VI A(n), B(n);
    REP(i, n) cin >> A.at(i);
    REP(i, n) cin >> B.at(i);

    int total = 0;
    int win_game = 0;

    sort(ALL(A));

    do {
        sort(ALL(B));
        do {
            int win = 0;
            REP(i, n) {
                if(A.at(i) > B.at(i)) win++;
            }
            if (win > (double)n/2) win_game++;
            total++;

        } while (next_permutation(ALL(B)));

    } while (next_permutation(ALL(A)));

    cout << setprecision(4) << (double)win_game/total << endl;
    
    return 0;
}