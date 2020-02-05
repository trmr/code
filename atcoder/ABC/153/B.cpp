#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int H, N; cin >> H >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    if (H - accumulate(A.begin(), A.end(), 0) > 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}