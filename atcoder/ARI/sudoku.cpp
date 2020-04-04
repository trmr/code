#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using Field = vector<vector<int>>;

#define REP(i, n) for (int i = 0; i < (n); i++)

void rec(Field &field, vector<Field> &res) {
    int emptyi = -1, emptyj = -1;
    for (int i = 0; i < 9 && emptyi == -1; i++) {
        for (int j = 0; j < 9 && emptyj == -1; j++) {
            if (field.at(i).at(j) == -1) {
                emptyi = i; emptyj = j;
                break;
            }
        }
    }

    if (emptyi == -1 || emptyj == -1) {
        res.push_back(field);
        return;
    }

    vector<bool> canuse(10, 1);

    for (int x = 0; x < 9; x++) {
        if (field.at(emptyi).at(x) != -1) canuse.at(field.at(emptyi).at(x)) = false;
        if (field.at(x).at(emptyj) != -1) canuse.at(field.at(x).at(emptyj)) = false;
        
        int bi = emptyi / 3 * 3; int bj = emptyj / 3 * 3;

        for (int di = bi; di < bi + 3; di++) {
            for (int dj = bj; dj < bj + 3; dj++) {
                if (field.at(di).at(dj) != -1) canuse.at(field.at(di).at(dj)) = false;
            }
        }
    }

    for (int x = 0; x < 9; x++) {
        if (!canuse.at(x)) continue;
        field.at(emptyi).at(emptyj) = x;
        rec(field, res);
        field.at(emptyi).at(emptyj) = -1;
    }

}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    return 0;
}