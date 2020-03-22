#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int array_sum_from_i(vector<int> &data, int i) {
    if (i == data.size()) return 0;

    int s = array_sum_from_i(data, i + 1);
    return data.at(i) + s;
}

int array_sum(vector<int> data) {

    return array_sum_from_i(data, 0);

} 

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<int> a = {0, 3, 9, 1, 5};

    cout << array_sum(a) << endl;
    
    return 0;
}