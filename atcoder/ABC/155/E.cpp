#include <iostream>
#include <string>

using namespace std;
using ll = long long;


int main() {
    string N; cin >> N;
    int len = N.length();
    int k[len];
    for (int i = 0; i < len; i++) {
        k[i] = N[i] - '0';
    }
    int d[len][2];
    d[0][0] = k[0];
    d[0][1] = 11 - k[0];

    for (int i = 1; i < len; i++) {
        d[i][0] = min(d[i-1][0] + k[i], d[i-1][1] + k[i]);
        d[i][1] = min(d[i-1][0] + 11 - k[i], d[i-1][1] + 9 - k[i]);
    }
    cout << min(d[len - 1][0], d[len - 1][1]) << endl;
    return 0;
}