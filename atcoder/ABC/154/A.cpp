#include <iostream>
#include <string>
using namespace std;

int main() {
    string S, T; cin >> S >> T;
    int a, b; cin >> a >> b;
    string U; cin >> U;

    if (S == U) a--;
    else b--;

    cout << a << " " << b << endl;

    return 0;
}