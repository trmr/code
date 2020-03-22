#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, a, b;
  cin >> x >> a >> b;

  // 1.の出力
  x++;
  cout << x << endl;

  x *= (a + b);

  // ここにプログラムを追記
  cout << x << endl;

  x *= x;

  cout << x << endl;

  x--;

  cout << x << endl;

  return 0;

}
