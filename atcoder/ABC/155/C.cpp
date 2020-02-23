#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool mycomp(pair<string, int> a, pair<string, int>b) {
    if (a.second == b.second) return a.first.compare(b.first) < 0;
    return a.second > b.second;
}

int main() {
    int N; cin >> N;
    string S;
    map<string, int> cnt;
    for (int i= 0; i<N; i++) {
        cin >> S;
        cnt[S]++;
    }
    vector<pair<string, int>> v;
    for (auto x = cnt.begin(); x != cnt.end(); x++) {
        v.push_back(make_pair(x->first, x->second));
    }
    sort(v.begin(), v.end(), mycomp);
    int max = v[0].second;
    for (auto& x:v) {
        if (max == x.second) {
            cout << x.first << endl;
        }else break;
    }
    return 0;
}