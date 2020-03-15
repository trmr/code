#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> L = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    int K; cin >> K;

    cout << L[K-1] << endl;

    return 0;

}