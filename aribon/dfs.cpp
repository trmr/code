#include <cstdio>

int n, k;

bool dfs(int i, int sum, int a[]) {
    if (i == n) return sum == k;
    
    if (dfs(i + 1, sum, a)) return true;

    if (dfs(i + 1, sum + a[i], a)) return true;


    return false;
}

int main(void) {
    scanf("%d", &n);
    int a[n] = {0};
    for (int i = 0; i < n; i++ ) {
        scanf("%d", &a[i]);
    }
    
    puts("---");

    scanf("%d", &k);
    if (dfs(0, 0, a)) printf("Yes\n");
    else printf("No\n");
    return 0;
}