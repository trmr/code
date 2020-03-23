#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int N; cin >> N;
    vector<pair<int, int>> A(N);
    REP(i, N) {
        int a, b;
        cin >> a >> b;
        A.at(i) = make_pair(b, a);
    }

    sort(A.begin(), A.end());

    REP(i, N) {
        cout << A.at(i).second << " " << A.at(i).first << endl;
    }

    return 0;
}