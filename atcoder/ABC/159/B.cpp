#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

bool judge_kaibun(string S) {
    string S2(S);
    reverse(S2.begin(), S2.end());
    for (int i = 0; i < S.size(); i++) {
        if (S[i] != S2[i]) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    int len = s.size();
    int b1 = (len - 1)/2;
    int b2 = (len + 3)/2;

    if (judge_kaibun(s) && judge_kaibun(s.substr(0, b1)) && judge_kaibun(s.substr(b2-1))) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}