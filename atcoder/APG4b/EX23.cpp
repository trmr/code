#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int N; cin >> N;
    map<int, int> A;
    REP(i, N) {
        int a; cin >> a;
        if (A.count(a)) {
            A.at(a)++;
        } else {
            A[a] = 1;
        }
    }

    int max_cnt = 0;
    int ma = 0;

    for (auto x:A) {
        if (x.second > max_cnt) {
            max_cnt = x.second;
            ma = x.first;
        }
    }

    cout << ma << " " << max_cnt << endl;
    return 0;
}