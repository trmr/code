#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int N;
set<string> Slist;

int search(string S, int pos, vector<char> used) {
    if (pos == N + 1) {
        Slist.insert(S);
        return 0;
    }

    char c = S.back() + 1;

    S.push_back(c);
    used.push_back(c);
    search(S, pos+1, used);

    S.pop_back();
    used.pop_back();

    for (auto& x:used) {
        S.push_back(x);
        search(S, pos+1, used);
        S.pop_back();
    }

    return 0;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    string S = "a";
    vector<char> used(1, 'a');
    int pos = 2;

    if (N == 1) {
        Slist.insert(S);
    } else if (N >= 2) {
        search(S, pos, used);
    }

    for (auto& x:Slist) {
        cout << x << endl;
    }

    return 0;
}
