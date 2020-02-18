#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, n) for (int i = 0; i < n; i++)

int n, W;
vector<pair<int, int>> wv;
vector<vector<int>> dp;

void solve() {
    for (int i = 0; i < n; i++) {
        for (int rest_w = 0; rest_w <= W; rest_w++) {
            if (rest_w < wv[i].first) dp[i + 1][rest_w] = dp[i][rest_w];
            else dp[i+1][rest_w] = max(dp[i][rest_w], dp[i][rest_w - wv[i].first] + wv[i].second);
        } 
    }
    cout << dp[n][W] << endl;
}


int main() {
    cin >> n >> W;
    wv.assign(n, pair<int, int>());
    dp.assign(n+1, vector<int>(W+1));
    for (auto& i : wv) cin >> i.first >> i.second;
    solve();
    return 0;

}
