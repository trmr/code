#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N); for(auto& x: A) cin >> x;

    bool flag = true;

    for (auto& x:A) {
        if (x % 2 == 0) if (x % 3 != 0 && x % 5 != 0) flag = false;
    }

    if (flag) cout << "APPROVED" << endl;
    else cout << "DENIED" << endl;

    return 0;
}