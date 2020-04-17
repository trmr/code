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
    string s, t;
    cin >> s;
    cin >> t;

    vector<string> candidate;

    int len_s = s.size();
    int len_t = t.size();


    for (int first = 0; first <= len_s - len_t; first++) {
        bool flag = true;
        for(int i = first; i < first + len_t; i++) {
            if (s.at(i) != t.at(i - first) && s.at(i) != '?'){
                flag = false;
                break;
            }
        }
        if (flag) {
            string s2 = s;
            for(int i = 0; i < len_t; i++) {
                s2.at(first + i) = t.at(i);
            }
            for(int i = 0; i < len_s; i++) {
                if (s2.at(i) == '?') s2.at(i) = 'a';
            }
            candidate.push_back(s2);
        }
    }

    if (candidate.empty()) {
        cout << "UNRESTORABLE" << endl;
    } else {
        sort(ALL(candidate));
        cout << candidate.at(0) << endl;
    }

    return 0;
}