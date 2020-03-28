#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int cnt = 0;
vector<int> cost = {500, 100, 50};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int A, B, C;
    int X;
    cin >> A >> B >> C >> X;

    int a = X / A;
    int ma = X % A;
    int b = ma / B;
    int mb = ma % B;
    int c = mb / C;
    int mc = mb % C;

    if (mc) {
        cout << 0 << endl;
        return 0;
    }

    



    
}