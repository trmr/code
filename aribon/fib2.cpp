#include <cstdio>

int fib(int n, int memo[]) {
    if (n <= 1) return n;
    if (memo[n] != 0) return memo[n];
    return memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
}

int main() {
    int n;
    scanf("%d", &n);
    int memo[n+1] = {0};

    int result = fib(n, memo);

    printf("%d", result);
    return 0;
}