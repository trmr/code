#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    

    int n; cin >> n;
    map<char, int> I;
    map<char, vector<int>> V;
    while (n) {
        string cmd; cin >> cmd;
        if (cmd == "int") {
            char var; cin >> var;
            char op; cin >> op;
            int tmp; cin >> tmp; 
            REP(i, 5) {
                cin >> op;
                if (op == ';') {
                    I.insert(make_pair(var, tmp));
                    break;
                } else if (op == '+') {
                    char tmp_v; cin >> tmp_v;
                    if (I.count(tmp_v)) {
                        tmp += I.at(tmp_v);
                    } else {
                        tmp += tmp_v - '0';
                    }
                } else if (op == '-') {
                    char tmp_v; cin >> tmp_v;
                    if (I.count(tmp_v)) {
                        tmp -= I.at(tmp_v);
                    } else {
                        tmp -= tmp_v - '0';
                    }
                }
            }

        } else if (cmd == "print_int") {
            char var; cin >> var;
            int tmp = I.at(var);
            REP(i, 5) {
                char op; cin >> op;
                if (op == ';') {
                    cout << tmp << endl;
                    break;
                } else if (op == '+') {
                    char tmp_v; cin >> tmp_v;
                    if (I.count(tmp_v)) {
                        tmp += I.at(tmp_v);
                    } else {
                        tmp += tmp_v - '0';
                    }
                } else if (op == '-') {
                    char tmp_v; cin >> tmp_v;
                    if (I.count(tmp_v)) {
                        tmp -= I.at(tmp_v);
                    } else {
                        tmp -= tmp_v - '0';
                    } 
                }
            }

        } else if (cmd == "vec") {
            char var; cin >> var;
            char op; cin >> op;

            vector<int> tmp;
            REP(i, 5) {
                if (op == ';') {
                    V.insert(make_pair(var, tmp));
                    break;
                } else if (op == '[') {
                    while (true) {
                        int v; cin >> v;
                        tmp.push_back(v);
                        cin >> op;
                        if (op == ']') break;
                    }
                    
                }
            }
            
        } else if (cmd == "print_vec") {


        } 
        n--;
    }


    return 0;
}