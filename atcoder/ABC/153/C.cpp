#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;


int main() {
    ll N, K; cin >> N >> K;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];
    sort(H.begin(), H.end());
    if (N <= K) {cout << 0 << endl; return 0;}
    for (int i = 0; i < K; ++i) H.pop_back();
    ll sum = 0;
    for (auto& n : H) sum += n;
    cout << sum << endl;
    return 0;
}