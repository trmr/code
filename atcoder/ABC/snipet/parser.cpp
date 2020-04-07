#include <bits/stdc++.h>

using namespace std;

template<class T> struct Parser {
    // results
    int root;                       // vals[root] is the answer
    vector<T> vals;                 // value of each node
    vector<char> ops;               // operator of each node ('a' means leaf values)
    vector<int> left, right;        // the index of left-node, right-node
    vector<int> ids;                // the node-index of i-th value
    int ind = 0;

    void init() {
        vals.clear(); ops.clear(); left.clear(); right.clear(); ids.clear();
        ind = 0;
    }

    // generate nodes
    int newnode(char op, int lp, int rp, T val = 0) {
        ops.push_back(op); left.push_back(lp); right.push_back(rp);
        if (op == 'a') {
            vals.push_back(val);
            ids.push_back(ind++);
        }
        else {
            if (op == '+') vals.push_back(vals[lp] + vals[rp]);
            else if (op == '-') vals.push_back(vals[lp] - vals[rp]);
            else if (op == '*') vals.push_back(vals[lp] * vals[rp]);
            else if (op == '/') vals.push_back(vals[lp] / vals[rp]);
            ids.push_back(-1);
        }
        return (int)vals.size() - 1;
    }

    // main solver
    T solve(const string &S) {
        int p = 0;
        string nS = "";
        for (auto c : S) if (c != ' ') nS += c;
        root = expr(nS, p);
        return vals[root];
    }

    // parser
    int expr(const string &S, int &p) {
        int lp = factor(S, p);
        while (p < (int)S.size() && (S[p] == '+' || S[p] == '-')) {
            char op = S[p]; ++p;
            int rp = factor(S, p);
            lp = newnode(op, lp, rp);
        }
        return lp;
    }

    int factor(const string &S, int &p) {
        int lp = value(S, p);
        while (p < (int)S.size() && (S[p]== '*' || S[p] == '/')) {
            char op = S[p]; ++p;
            int rp = value(S, p);
            lp = newnode(op, lp, rp);
        }
        return lp;
    }

    int value(const string &S, int &p) {
        if (S[p] == '(') {
            ++p;                    // skip '('
            int lp = expr(S, p);
            ++p;                    // skip ')'
            return lp;
        }
        else {
            T val = 0;
            int sign = 1;
            if (p < (int)S.size() && S[p] == '-') sign = -1;
            while (p < (int)S.size() && S[p] >= '0' && S[p] <= '9') {
                val = val * 10 + (int)(S[p] - '0');
                ++p;
            }
            return newnode('a', -1, -1, val);
        }
    }
};


int main() {
    Parser<int> parse;
    cout << parse.solve("6 + 3") << endl;
    cout << parse.solve("3 + (10 - 4) / 2") << endl;
    cout << parse.solve("((6 - 3) * 2 + 10 / 5) * (-3)") << endl;
}