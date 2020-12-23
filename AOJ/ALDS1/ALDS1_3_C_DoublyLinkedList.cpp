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

struct DoubleLinkedList {
    int key;
    DoubleLinkedList* prev;
    DoubleLinkedList* next;
};

DoubleLinkedList* nil;

void init() {
    nil = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
    nil->next = nil;
    nil->prev = nil;
}

void insert(int key) {
    DoubleLinkedList *x = (DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));
    x->key = key;
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

DoubleLinkedList* listSearch(int key) {
    DoubleLinkedList *cur = nil->next;
    while (cur != nil && cur->key != key) {
        cur = cur->next;
    }
    return cur;
}

void deleteNode(DoubleLinkedList *t) {
    if (t == nil) return;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}

void deleteFirst() {
    deleteNode(nil->next);
}

void deleteLast() {
    deleteNode(nil->prev);
}

void deleteKey(int key) {
    deleteNode(listSearch(key));
}

void printNode(DoubleLinkedList *t) {
    t = t->next;
    cout << t->key;
    if (t->next == nil) {
        cout << endl;
        return;
    }else {
        cout << " ";
    }
    printNode(t);
}



int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    init();


    REP(i, n) {
        string cmd;
        cin >> cmd;
        if (cmd == "insert") {
            int x;
            cin >> x;
            insert(x);
        } else if (cmd == "delete") {
            int x;
            cin >> x;
            deleteKey(x);
        } else if (cmd == "deleteFirst") {
            deleteFirst();
        } else if (cmd == "deleteLast") {
            deleteLast();
        }
    }

    printNode(nil);


    return 0;
}