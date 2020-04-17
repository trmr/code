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

const int mod = 1000000007;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    int N; cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A.at(i);
    int M; cin >> M;
    vector<int> B(M);
    REP(i, M) cin >> B.at(i);

    int total = 0;

    REP(i, M) {
        int b = B.at(i);
        REP(idx, A.size()) {
            if ((A.at(idx) <= b) && (b <= A.at(idx) + T)) {
                A.erase(A.begin() + idx);
                total++;
                break;
            }
        }
    }

    if (total == M) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}