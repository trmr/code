#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using Field = vector<vector<int>>;
using Graph = vector<vector<int>>;
using VI = vector<int>;
using VC = vector<char>;
using PI = pair<int, int>;
using Matrix = vector<vector<ll>>;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const long long INF = 1LL<<60;
const int mod = 1000000007;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

int N;
ll K;
Matrix A;

Matrix matmul(Matrix &A, Matrix &B) {
    Matrix res(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                res.at(i).at(j) = (res.at(i).at(j) + A.at(i).at(k) * B.at(k).at(j)) % mod;
            }
        }
    }
    return res;
}

Matrix matpow(Matrix M, ll k) {
    Matrix res(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) res.at(i).at(i) = 1;

    while (k > 0) {
        if (k & 1) res = matmul(res, M);
        M = matmul(M, M);
        k >>= 1;
    }
    return res;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    A.assign(N, vector<ll>(N));

    REP(i, N) {
        REP(j, N) {
            cin >> A.at(i).at(j);
        }
    }

    A = matpow(A, K);

    ll ans = 0;
    REP(i, N) {
        REP(j, N) {
            ans += A.at(i).at(j);
            ans %= mod;
        }
    }

    cout << ans << endl;
    
    return 0;
}