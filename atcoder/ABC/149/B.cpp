#include <iostream>
#include <cmath>

const long long MAX_A = std::pow(10, 12);
const long long MAX_B = std::pow(10, 12);
const long long MAX_K = std::pow(10, 12);

long long A, B, K;
long long out_A, out_B;

int main() {
    std::cin >> A >> B >> K;
    if (K < A) {
        out_A = A - K;
        out_B = B;
    } else if (A <= K &&  K < (A + B)) {
        out_A = 0;
        out_B = A + B - K;
    } else if ((A + B) <= K) {
        out_A = 0;
        out_B = 0;
    }
    std:: cout << out_A << " " << out_B;
    return 0;
}