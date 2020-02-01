#include <stdio.h>
#include <algorithm>
using namespace std;

const int V[6] = {1, 5, 10, 50, 100, 500};

int C[6];
int A;

int solve() {
  int ans = 0;

  for (int i = 5; i >= 0; i--) {
    int t = min(A / V[i], C[i]);
    A -= t * V[i];
    ans += t;
  }
  printf("%d¥n", ans);
}


int main(void){
  C[0] = 3;
  C[1] = 2;
  C[2] = 1;
  C[3] = 3;
  C[4] = 0;
  C[5] = 2;
  A = 620;
  solve();
}
