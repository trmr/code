#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 1000;

int N, R;
int X[MAX_N];

void solve() {
  sort(X, X + N);

  int i = 0, ans = 0;

  while (i < N) {
    int s = X[i++];
    while (i < N && X[i] <= s + R) i++;
    int p = X[i - 1];
    while (i < N && X[i] <= p + R) i++;
    ans++;
  }
  cout << ans;
}

int main() {
  N = 6;
  R = 10;
  X[0] = 1;
  X[1] = 7;
  X[2] = 15;
  X[3] = 20;
  X[4] = 30;
  X[5] = 50;
  solve();
}
