#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Field = vector<vector<ll>>;
using Graph = vector<vector<ll>>;
using VI = vector<int>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VC = vector<char>;
using PI = pair<int, int>;

#define FOR(i, s, n) for (int i = s; i < (n); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const long long INF = 1LL<<60;
const int mod = 1000000007;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

int N;
vector<ll> A, B;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    A.resize(N);
    B.resize(N);

    REP(i, N) {
        cin >> A[i] >> B[i];
    }
    
    sort(ALL(A));
    sort(ALL(B));

    ll ans = 0;

    if (N%2) {
        ll min = A[N/2];
        ll max = B[N/2];
        ans = max - min + 1;
    } else {
        ll min = A[N/2-1] + A[N/2];
        ll max = B[N/2-1] + B[N/2];
        ans = max - min + 1;
        
    }

    cout << ans << endl;




    return 0;
}