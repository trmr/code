#include <cstdio>
#include <algorithm>

const int MAX_N = 100;

int main() {
    int ans = 0;
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int len = a[i] + a[j] + a[k];
                int ma = std::max(a[i], std::max(a[j], a[k]));
                int rest = len - ma;
                if (ma < rest) {
                    ans = std::max(ans, len);
                }

            }
        }
    }

    printf("%d\n", ans);
    
}