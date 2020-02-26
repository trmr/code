#include <iostream>
#include <vector>

using namespace std;
using ll = long long;


int main() {
    int k, q; cin >> k >>q;
    vector<int> d(k), e(k); for (auto& x:d) cin >> x;
    vector<int> n(q), x(q), m(q);
    for (int i = 0; i < q; ++i) {
        cin >> n[i] >> x[i] >> m[i];
    }
    for (int i = 0; i < q; ++i) {
        ll zero = 0;
        ll sum = 0;
        for (int j = 0; j < k; ++j){
            e[j] = d[j] % m[i]; 
            if (e[j] == 0) zero++;
            sum += e[j];
        }

        sum *= (n[i]-1)/k;
        zero *= (n[i]-1)/k;

        for (int j = 0; j < (n[i] -1) % k; ++j) {
            e[j] = d[j] % m[i];
            sum += e[j];
            if (e[j] == 0) zero++;
        }
        ll Q = ((x[i] + sum) / m[i]) - (x[i] / m[i]);

        cout << n[i] - 1 - Q - zero << endl;
    }

    return 0;
}
