#include <iostream>
#include <cstdio>

using namespace std;


int N, K, M;
int A[100] = {0};

void solve() {

    int tmp = 0, ans = 0;
    for (int i = 0; i < N - 1; i++) {
        tmp += A[i];
    }

    ans = N * M - tmp;

    if (ans > K) {
        cout << -1 << endl;
    } else if (ans <= 0) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }

}

int main() {
    cin >> N >> K >> M;
    for (int i = 0; i < N-1; i++) {
        cin >> A[i];
    }

    solve();

    return 0;
}