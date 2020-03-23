#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int N, K; cin >> N >> K;
    vector<int> A(N);
    REP(i, N) cin >> A.at(i);

    bool flag = false;

    for (int tmp = 0; tmp < (1 << 20); tmp++) {
        bitset<20> s(tmp);

        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (s.test(i)) {
                sum += A.at(i);
            }
        }
        if (sum == K) {
            flag = true;
        }
    }

    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}