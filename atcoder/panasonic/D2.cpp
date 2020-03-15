#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int N;
string S = "";
set<string> Slist;

void dfs(int pos) {
    if (pos == N) {
        Slist.insert(S);
        return;
    }

    char c = 'a';

    while (S.find(c) != string::npos) c++;
    c--;

    for (char i = 'a'; i <= c + 1; i++) {
        S.push_back(i);
        dfs(pos + 1);
        S.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> N;

    dfs(0);

    for (auto& x:Slist) {
        cout << x << endl;
    }

    return 0;
}
