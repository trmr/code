#include <iostream>
#include <string>

using namespace std;

#define FOR(i, n) for(int (i) = 0; (i) < (n); (i)++)

int N;
int P[200000];

int main() {
    cin >> N;
    FOR(i, N) cin >> P[i];

    int ans = 0;
    int min = N + 1;

    FOR(i, N) {
        if (min >= P[i]) {
            ans += 1;
            min = P[i];
        }
    }

    cout << ans << endl;

    return 0;
}