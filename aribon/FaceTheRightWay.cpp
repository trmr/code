#include <bits/stdc++.h>

using namespace std;

int calc(int l, vector<int> DIR, int n) {
    vector<int> F(n, 0);
    int res = 0, sum = 0;

    for (int i = 0; i + l <= n; i++) {
        if ((DIR[i] + sum) % 2 != 0) {
            res++;
            F[i] = 1;
        }
        sum += F[i];
        if (i - l + 1 >= 0) {
            sum -= F[i - l + 1];
        }
    }

    for (int i = n - l + 1; i < n; i++) {
        if ((DIR[i] + sum) % 2 != 0) {
            return -1;
        }
        if (i - l + 1 >= 0) {
            sum -= F[i - l + 1];
        }
    }

    return res;
}

int main() {
    int n; cin >> n;
    vector<int> DIR(n);
    for (auto& d:DIR) cin >> d;

    int len = 1, cnt = n;

    for (int l = 1; l <= n; l++) {
       int m = calc(l, DIR, n);
       if (m >= 0 && cnt > m) {
           cnt = m;
           len = l;
       }
    }

    cout << len << " " << cnt << endl;

    return 0;

}