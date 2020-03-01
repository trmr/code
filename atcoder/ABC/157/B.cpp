#include <iostream>
#include <vector>

using namespace std;

using P = pair<int, bool>;

int main() {
    vector<vector<P>> A(3, vector<P>(3));
    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++){
        cin >> A[i][j].first;
        A[i][j].second = false;
    }
    int N; cin >> N;
    vector<int> B(N);
    for (auto& b:B) {cin >> b;}

    for (auto& b:B) {
        for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if (b == A[i][j].first) A[i][j].second = true;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (
            (A[i][0].second && A[i][1].second && A[i][2].second) ||
            (A[0][i].second && A[1][i].second && A[2][i].second) ||
            (A[0][0].second && A[1][1].second && A[2][2].second) ||
            (A[2][0].second && A[1][1].second && A[0][2].second)
        ){
            cout << "Yes" << endl;
            return 0;
        } 

    }
    cout << "No" << endl;

    return 0;
}