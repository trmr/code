#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int check(int src, string s){
    string subs = s.substr(src, 5);
    if (subs == "dream") {
        if (s.substr(src + 5, 5) == "erase") {
            return src + 5;
        } else if (s.substr(src + 5, 2) == "er") {
            return src + 7;
        } else {
            return src + 5;
        }
    } else if (subs == "erase") {
        if (s.substr(src + 5, 1) == "r") {
            return src + 6;
        } else {
            return src + 5;
        }
    } else {
        return -1;
    }
} 

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    string s; cin >> s;

    int src=0;
    int size = s.size();

    while (true) {
        src = check(src, s);
        if (src == -1) {
            cout << "NO" << endl;
            break;
        }

        if (src >= size) {
            cout << "YES" << endl;
            break;
        }

    }
    return 0;
}