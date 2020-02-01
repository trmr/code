#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)

int N;
int count = 0;

int main() {
    cin >> N;

    long long res = 0;

     vector<vector<long long>> num(10, vector<long long>(10, 0));   for (int i = 1; i <= N; i++) {
        vector<int> d;
        int nn = i;
        while (nn) {
            d.push_back(nn % 10);
            nn /= 10;
        }
        int a = d[0];
        int b = d.back();
        if (!a || !b) continue;
        num[a][b]++;
    }
    for (int a = 1; a < 10; a++) {
        for (int b = 1; b < 10; b++) {
            res += num[a][b] * num[b][a];
        }
    }

    cout << res << endl;

    return 0;
}