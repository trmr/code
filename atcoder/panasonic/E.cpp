#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1e9;

#define REP(i, n) for (int i = 0; i < (n); i++)

vector<bool> matching(string x, string y) {
    int nx = x.size();
    int ny = y.size();

    vector<bool> res(6010, true);

    REP(st, nx) {
        for (int i = 0; st + i < nx && i < ny; i++) {
            if (x[st + i] == '?') continue;
            if (y[i] == '?') continue;
            if (x[st + i] != y[i]) res[st] = false;
        }
    }

    return res;
}

int solve(string A, string B, string C) {
    int na = A.size();
    int nb = B.size();
    int nc = C.size();

    auto ab = matching(A, B);
    auto bc = matching(B, C);
    auto ac = matching(A, C);

    int ans = INF;
    REP(a, na + 1) {
        REP (b, max(na, nb) + 1) {
            if (ab[a] && bc[b] && ac[a + b]) {
                if (ans > max({na, a + nb, a + b + nc})) {
                    ans = max({na, a + nb, a + b + nc});
                }
            }
        }
    }
    return ans;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<string> v;
    REP(i, 3) {
        string s; cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());

    int ans = INF;

    do {
        if (ans > solve(v[0], v[1], v[2])) {
            ans = solve(v[0], v[1], v[2]);
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;

    return 0;
}