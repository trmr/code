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

int N;
struct Infant{
    ll act;
    int x;
};
vector<Infant> A;

vector<vector<ll>> dp(2010, vector<ll>(2010, 0));


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    A.resize(N);
    REP(i, N) {
        ll a; cin >> a;
        A.at(i).act = a;
        A.at(i).x = i;
    }

    deque<int> deq;

    REP(i, N) {
        deq.push_back(i);
    }

    sort(ALL(A), [] (Infant la, Infant ra) {return la.act > ra.act;});

    ll ans = 0;

    REP(i, N) {
        for (int j = 0; i + j < N; j++) {
            ll act = A.at(i + j).act;
            int x = A.at(i + j).x;

            chmax(dp.at(i + 1).at(j), dp.at(i).at(j) + act * (x - i));
            chmax(dp.at(i).at(j + 1), dp.at(i).at(j) + act * ((N - 1 - j) - x));
        }      
    }

    REP(i, N) {
        chmax(ans, dp.at(i).at(N - i));
    }

    cout << ans << endl;
    
    return 0;
}