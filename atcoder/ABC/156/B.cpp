#include <iostream>

using namespace std;

int main() {
    int N, K; cin >> N >> K;

    int ans = 0;

    while (true) {
        if ((N = N / K) == 0) break;
        ans++;
    }
    cout << ans + 1 << endl;

    return 0;
}