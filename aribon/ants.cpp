#include <cstdio>
#include <algorithm>

int main(){
    int L, n;
    
    scanf("%d", &L);
    scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    int minT = 0;
    for (int i = 0; i < n; i++) {
        minT = std::max(minT, std::min(x[i], L - x[i]));
    }

    int maxT = 0;
    for (int i = 0; i < n; i++) {
        maxT = std::max(maxT, std::max(x[i], L - x[i]));
    }

    printf("%d %d\n", minT, maxT);
}