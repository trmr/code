#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, L, P; cin >> N >> L >> P;
    vector<int> A(N), B(N);
    for (auto& x:A) cin >> x;
    for (auto& x:B) cin >> x;

    priority_queue<int> que;

    A.push_back(L);
    B.push_back(0);

    int ans = 0, pos = 0, tank = P;
    
    for (int i = 0; i < N; ++i) {
        int d = A[i] - pos;

        while (tank - d < 0) {
            if (que.empty()) {
                cout << -1 << endl;
                return 0;
            }

            tank += que.top();
            que.pop();
            ans++;
        }

        tank -= d;
        pos = A[i];
        que.push(B[i]);
    }
    cout << ans << endl;

}