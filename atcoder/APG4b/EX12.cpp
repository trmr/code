#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int N = S.size();

  int a;
  int sum = 0;
  char op;

  for (int i = 0; i < N; i++) {
      if (i % 2 == 0) {
          a = S.at(i) - '0';
          if (op == '+') sum += a;
          else if (op == '-') sum -= a;
          else sum = a;
      } else {
          op = S.at(i);
      }
  }

  cout << sum << endl;

  return 0;
}
