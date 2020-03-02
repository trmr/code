#include <iostream>
#include <vector>
#include <string>

using namespace std;


template <typename T>
struct BIT {
    private:
        vector<T> array;
        const int n;
    
    public:
        BIT(int n) : array(++n, 0), n(n) {}

        T sum(int i) {
            T ret = 0;
            for (++i; i > 0; i -= i & -i) ret += array[i];
            return ret;
        }

        void add(int i, T x) {
            for (++i; i < array.size(); i += i & -i) array[i] += x;
        }
};

int main() {
    int N, Q;
    string S;
    vector<BIT<int>> bt;
    for (int i = 0; i < 26; i++) {
        BIT<int> x(20);
        bt.push_back(x);
    }
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        bt[S[i] - 'a'].add(i, 1);
    }
    cin >> Q;
    while (Q--) {
        int i; cin >> i;
        if (i == 1) {
            int x;
            string s;
            cin >> x >> s;
            x--;
            bt[s[x] - 'a'].add(x, -1);
            S[x] = s[0];
            bt[S[x] - 'a'].add(x, 1);
        }
        else {
            int L, R;
            cin >> L >> R;
            L--, R--;
            int cnt = 0;
            for (int i = 0; i < 26; i++) {
                if (bt[i].sum(R) - bt[i].sum(L-1)) cnt++;
            }
            cout << cnt << endl;
        }
    }
    return 0;

}
