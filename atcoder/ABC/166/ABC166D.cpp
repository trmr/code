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

bool is_integer(long double x) {
    double xx = x;
    return floor(xx) == xx;
}

long double X;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> X;

    ll A = 0, B = 0;

    while (true) {
        ll b = pow(B, 5);
        long double a1 = X + b;
        long double a2 = X - b;
        long double a11 = pow(a1, (long double)1.0/5.0);
        long double a22 = pow(a2, (long double)1.0/5.0);
        if (is_integer(a11)) {
            A = a11;
            break;
        } else if (is_integer(a22)) {
            A = a22;
            B = -B;
            break;
        }
        B++;
    }

    cout << A << " " << B << endl;
    
    return 0;
}