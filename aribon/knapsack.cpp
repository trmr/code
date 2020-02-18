#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, W;
vector<pair<int, int>> wv;


int rec(int i, int rest_w) {
    int res;
    if (i == n) {
        res = 0;
    } else if (rest_w < wv[i].first) {
        res = rec(i+1, rest_w);
    } else {
        res = max(rec(i+1, rest_w), rec(i+1, rest_w-wv[i].first) + wv[i].second);
    }
    return res;
}


int main() {
    cin >> n >> W;
    wv.assign(n, pair<int, int>());
    for (auto& i : wv) cin >> i.first >> i.second;
    int ans = rec(0, W);
    cout << ans << endl;
    return 0;

}
