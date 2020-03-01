#include <iostream>
#include <vector>

using namespace std;
using P = pair<int, bool>;
using ll = long long;


int pow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}

int main() {
    int N, M; cin >> N >> M;
    vector<P> D(N);
    vector<int> S(M), C(M);
    for (int i = 0; i < M; i++) {
        cin >> S[i] >> C[i];
        S[i]--;
    }

    for (auto& d:D) {
        d.first = 0;
        d.second = false;
    }

    for (int i = 0; i < M; i++) {
        if (!D[S[i]].second) {
            D[S[i]].first = C[i];
            D[S[i]].second = true;
        } else if (D[S[i]].second && D[S[i]].first != C[i]) {
            cout << -1 << endl;
            return 0;
        } 
    }

    if (N > 1 && D[0].second && D[0].first == 0) {
        cout << -1 << endl;
        return 0;
    } else if (N > 1 && !D[0].second && D[0].first == 0) {
        D[0].first = 1;
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        ans += D[i].first * pow(10, (N-i-1));
    }

    cout << ans << endl;

    return 0;

}