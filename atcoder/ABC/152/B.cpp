#include <iostream>
#include <string>

using namespace std;

#define FOR(i, n) for(int (i) = 0; (i) < (n); (i)++)


int main() {
    string a, b, s1, s2;
    int na, nb;
    cin >> a >> b;
    na = atoi(a.c_str());
    nb = atoi(b.c_str());
    FOR(i, nb) s1 += a;
    FOR(i, na) s2 += b;
    if (s1 <= s2) cout << s1 << endl;
    else cout << s2 << endl;

    return 0;
}