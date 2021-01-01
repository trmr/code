#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cinttypes>
#include <cstdint>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <chrono>
#include <forward_list>
#include <initializer_list>
#include <random>
#include <regex>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using ll = long long;
using Field = vector<vector<ll>>;
using Graph = vector<vector<ll>>;
using VI = vector<int>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VC = vector<char>;
using PI = pair<int, int>;

#define FOR(i, s, n) for (int i = s; i < (n); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const long long INF = 1LL<<60;
const int MOD = 1000000007;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

struct Node {
    int id, left, right;
};

vector<Node> T;

void Preorder(int id) {
    if (id == -1) return;

    cout << " " << T[id].id;
    Preorder(T[id].left);
    Preorder(T[id].right);

    return;
}

void Inorder(int id) {
    if (id == -1) return;

    Inorder(T[id].left);
    cout << " " << T[id].id;
    Inorder(T[id].right);

    return;
    
}

void Postorder(int id) {
    if (id == -1) return;

    Postorder(T[id].left);
    Postorder(T[id].right);
    cout << " " << T[id].id;

    return;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    T.resize(n);

    vector<bool> R(n, true);
    int root;

    REP(i, n) {
        int a,b,c; cin >> a >> b >> c;
        T[a].id = a;
        T[a].left = b;
        T[a].right = c;
        if (b != -1) R[b] = false;
        if (c != -1) R[c] = false;
    }

    REP(i, n) {
        if (R[i]) {
            root = i; break;
        }
    }

    cout << "Preorder" << endl;
    Preorder(root);
    cout << endl;
    cout << "Inorder" << endl;
    Inorder(root);
    cout << endl;
    cout << "Postorder" << endl;
    Postorder(root);
    cout << endl;





    return 0;
}