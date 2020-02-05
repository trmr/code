#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ll H; cin >> H;
    int x = (int) floor(log2(H));
    ll sum = 0;
    for (int i = 0; i < x+1; ++i) {sum += pow(2, i);}
    cout << sum << endl;
    return 0;
}