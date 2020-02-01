#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int N;
const int MAX_N = 2000;
char S[MAX_N + 1];
vector<char> ans;

void solve() {
  int a = 0, b = N - 1;

  while (a <= b) {
    bool left = false;
    for (int i = 0; a + i <= b; i++) {
      if (S[a + i] < S[b - i]) {
        left = true;
        break;
      }
      else if (S[a + i] > S[b - i]) {
        left = false;
        break;
      }
    }
    if (left)  ans.push_back(S[a++]);
    else ans.push_back(S[b--]);
  }
  ans.push_back('\n');
  for (int i = 0; i < N; i++) printf("%c", ans[i]);
}

int main() {
  scanf("%d\n", &N);
  for (int i = 0; i < N; i++) {
    scanf("%c\n", &S[i]);
  }
  solve();
}
