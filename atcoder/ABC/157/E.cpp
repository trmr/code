#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
    int N; cin >> N;
    string _S; cin >> _S;
    vector<char> S(_S.size());
    for (int i = 0; i < _S.size(); i++) {
        S[i] = _S[i];
    }
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int type; cin >> type;
        if (type == 1) {
            int iq;
            char c;
            cin >> iq >> c; iq--;
            S[iq] = c;
        } else if (type == 2) {
            int lq, rq; cin >> lq >> rq; lq--, rq--;
            set<char> SC;
            for (int j = lq; j <= rq; j++) {
                SC.insert(S[j]);
            }
            cout << SC.size() << endl;
        }
    }


    return 0;
}