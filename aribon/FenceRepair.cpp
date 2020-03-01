#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

int N;
int L[3] = {8,5,8};

void solve(){
  ll ans = 0;
  priority_queue<int, vector<int>, greater<int>> q;
  for (int i = 0; i < N; ++i) {
    q.push(L[i]);
  }

  while (q.size() > 1) {
    int l1, l2;
    l1 = q.top();
    q.pop();
    l2 = q.top();
    q.pop();

    ans += l1 + l2;
    q.push(ans);
  }

  cout << ans << endl;
}

int main(void) {
  N = 3;
  solve();
}
