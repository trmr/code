#include <bits/stdc++.h>

using namespace std;

using Matrix = vector<vector<ll>>;
using ll = long long;

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
