#include <iostream>
#include <cmath>

const long long MAX_X = std::pow(10, 6);
long long X;

bool IsPrime(int num) {
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    std::cin >> X;
    if (IsPrime(X)) {
        std::cout << X;
        return 0;
    }

    if (X % 2 == 0) {
        X = X + 1;
    }

    for (int i = X; X < MAX_X; X += 2) {
        if (IsPrime(X)) {
            std::cout << X;
            break;
        }
    }
    return 0;
}