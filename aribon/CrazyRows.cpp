#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> M(n, vector<int>(n));
    vector<int> pos_1(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
            if (M[i][j] == 1) pos_1[i] = j;
        }
    }

    int src_row = 0;
    int dst_row = 0;
    int cnt = 0;

    int target_pos = 0;

    for (src_row = 0; src_row < n; src_row++) {

        for (int i = src_row; i < n; i++) {
            if (pos_1[i] <= target_pos) {
                dst_row = i;
                break;
            }
        }

        if (dst_row > src_row) {
            for (int j = dst_row; j > src_row; j--) {
                swap(pos_1[dst_row], pos_1[dst_row--]);
                cnt++;
            }
            target_pos++;
        }
    }

    cout << cnt << endl;

    return 0;

}