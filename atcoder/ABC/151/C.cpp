#include <iostream>
#include <string>

using namespace std;

#define REP(x,y) for (int (x) = 0; (x) < (y); (x)++)

int correct_result = 0, penalty = 0;

int correct[100000] = {};
int incorrect[100000] = {};

int N = 0, M = 0;
int p[100000] = {};
string S[100000] = {};

int main() {
    cin >> N >> M;
    REP(i, M) {
        cin >> p[i] >> S[i];
    }

    REP(i, M) {
        if (S[i] == "AC") {
            if (correct[p[i]] == 0) {
                correct[p[i]] = 1;
                correct_result += 1;
                penalty += incorrect[p[i]];
            }
        } else if (S[i] == "WA") {
            if (correct[p[i]] == 0) {
                incorrect[p[i]] += 1;
            }
        }
    }

    cout << correct_result << " " << penalty << endl;

    return 0;
}