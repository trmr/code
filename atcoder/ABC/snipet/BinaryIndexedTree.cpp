#include <iostream>
#include <vector>

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