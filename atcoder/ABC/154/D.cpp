#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<long long> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    vector<long long> sum(N+1);
    sum[0] = p[0];
    for (int i=0; i < N; i++) {
        sum[i+1] = sum[i] + p[i];
    }

    long long ans = 0;
    for (int i = 0; i+K <= N; ++i) {
        ans = max(ans, sum[i+K] - sum[i]); 
    }
    cout << fixed << setprecision(10) << (double)(ans+K)/2 << endl;
    return 0;
}