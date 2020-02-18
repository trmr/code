#include <iostream>
#include <set>
using namespace std;


int main() {
    int N; cin >> N;
    set<int> A; 
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        A.insert(a);
    }
    if (N == A.size()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}