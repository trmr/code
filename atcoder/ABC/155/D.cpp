#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int N;
ll K;
vector<ll> P, M, Z;

bool judge_m(ll mid) {
    ll sum = 0;
    for (int i = 0; i < (int)P.size(); i++) {
        ll d = (mid - P[i] + 1) / P[i];
        sum += upper_bound(M.begin(), M.end(), d) - M.begin();
    }
    return sum >= K;
}

bool judge_p(ll mid) {
    ll sum = 0;
    for (int i = 0; i < (int)P.size(); ++i) {
        ll d = mid / P[i];
        ll tmp = upper_bound(P.begin(), P.end(), d) - P.begin();
        if (i < tmp) tmp--;
        sum +=tmp;
    }
    for (int i = 0; i < (int)M.size(); ++i) {
        ll d = mid / M[i];
        ll tmp = upper_bound(M.begin(), M.end(), d) - M.begin();
        if (i < tmp) tmp--;
        sum += tmp;
    }
    sum /= 2;
    return sum >= K;
}

const int MAX = 510000;
const int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

int main() {

    cin >> N >> K;
    vector<ll> A(N); for (auto& x:A) cin >> x;
    for (auto& x:A) {
        if (x > 0) {
            P.push_back(x);
        } else if (x < 0) {
            M.push_back(x);
        } else {
            Z.push_back(x);
        }
    }
    ll p = P.size();
    ll m = M.size();
    ll z = Z.size();

    ll minus = p * m;
    ll zero = z * (z - 1) / 2 + z * p + z * m;
    ll plus = p * p + m * m;
    
    if (K <= minus){
        sort(M.begin(), M.end());
        ll l = -1e18 - 1, u = -1;
        while (u - l > 1) {
            ll mid = (u + l) / 2;
            if (judge_m(mid)) {
                u = mid;
            } else {
                l = mid;
            }
        }
        cout << u << endl;
    }else if (K <= minus + zero) {
        cout << 0 << endl;
    }else {
        K -= (minus + zero);
        for (int i = 0; i < m; ++i) {
            M[i] = abs(M[i]);
        }
        sort(P.begin(), P.end());
        sort(M.begin(), M.end());
        ll l = -1, u = 1e18;
        while (u - l > 1) {
            ll mid = (u + l) / 2;
            if (judge_p(mid)) {
                u = mid;
            } else {
                l = mid;
            }
        }
        cout << u << endl;
    }
    return 0;
}