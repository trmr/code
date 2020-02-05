#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <tuple>

using namespace std;
using LL = long long;
#define REP(i, n) for(int i = 0; i < n; ++i)

 int main() {
  
     LL N, D, A;
     cin >> N >> D >> A;
     D *= 2;
  
     vector<pair<LL, LL>> XH(N);
     REP(i, N) {
         int x, h;
         cin >> x >> h;
         //h = CE(h, A);
         XH[i] = make_pair(x, h);
     }
     sort(XH.begin(), XH.end());
  
     LL ans = 0;
     LL bomb = 0;
     queue<pair<LL, LL>> Q;
  
     for (int i = 0; i < N; i++) {
         LL x, h;
         tie(x, h) = XH[i];
         while (!Q.empty() and x > Q.front().first) {
             bomb -= Q.front().second;
             Q.pop();
         }
         if (h <= bomb)continue;
         LL add = h - bomb;
         ans += add;
         bomb += add;
         Q.push(make_pair(x + D, add));
     }
  
     cout << ans << endl;
  
 }