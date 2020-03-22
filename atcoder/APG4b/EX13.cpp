#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    int sum = 0;
    for (auto& x:A) {
        cin >> x;
        sum += x;
    }
    int ave = sum / N;

    for (auto& x:A) {
        int dif = x - ave;
        if (dif < 0) dif = -dif;
        cout << dif << endl;
    }

    return 0;


}