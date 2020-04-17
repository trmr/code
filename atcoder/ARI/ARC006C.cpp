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

    int N; cin >> N;
    vector<int> W(N);
    REP(i, N) cin >> W.at(i);

    vector<int> boxes;
    boxes.push_back(W.at(0));

    for (int i = 1; i < N; i++) {
        auto itr = lower_bound(ALL(boxes), W.at(i));
        if (itr == boxes.end()) {
            boxes.push_back(W.at(i));
        } else {
            *itr = W.at(i);
        }
        sort(ALL(boxes));
    }

    int ans = boxes.size();

    cout << ans << endl;
    
    return 0;
}