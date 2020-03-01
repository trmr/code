#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;

    int X = N/2;
    int Y = N%2;
    if (Y == 1) {
        X++;
    }
    cout << X << endl;

    return 0;
}