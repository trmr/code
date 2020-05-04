#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using Field = vector<vector<int>>;
using Graph = vector<vector<int>>;
using VI = vector<int>;
using VC = vector<char>;
using PI = pair<int, int>;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const long long INF = 1LL<<60;
const int mod = 1000000007;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

int N, M;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    int a = 1;
    int b = N;
    set<int> s;

    for (int m = 1; m <= M; m++) {
        if ((s.find(abs(a - b)) != s.end()) || (s.find(abs(N + a - b) % N) != s.end()) || abs(a - b) == abs((N + a - b) % N)) {
            cout << a << " " << b - 1 << endl;
        } else {
            cout << a << " " << b << endl;
        }
        s.insert(abs(a - b));
        s.insert(abs((N + a - b)%N));
        a++;
        b--;
    }

    return 0;
    
}