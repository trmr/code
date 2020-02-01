#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

int N;
std::string s[1000];
int t[1000];
std::string X;

void solve() {
    int i;
    int u = 0;
    for (i = 0; i < N; i++) {
        if (X == s[i]) {
            break;
        }
    }
    for (int j = i + 1; j < N; j++) {
        u += t[j];
    }
    std::cout << u << std::endl;
}

int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> s[i] >> t[i];
    }
    std::cin >> X;

    solve();

    return 0;

}