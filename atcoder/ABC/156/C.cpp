#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<int> X(N); for (auto& x:X) cin >> x;

    float sum = 0;

    for (int i = 0; i < N; i++) {
        sum += X[i];
    }

    int ave = (int) sum / N;
    int ave2 = ave + 1;

    ll ans = 0;
    ll ans2 = 0;
    for (auto& x:X) ans += (x - ave) * (x - ave);
    for (auto& x:X) ans2 += (x - ave2) * (x - ave2);


    cout << min(ans, ans2) << endl;

    return 0;
}