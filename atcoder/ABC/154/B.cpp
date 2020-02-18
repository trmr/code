#include <iostream>
#include <string>
using namespace std;

int main() {
    string S; cin >> S;
    string x;
    for (auto& a: S) {
        x += "x";
    }
    cout << x << endl;

    return 0;

}