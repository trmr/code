#include <cstdio>
#include <algorithm>


const int MAX_N = 100;

bool used[MAX_N];
int perm[MAX_N];

void permutation1(int pos, int n) {
    if (pos == n) {
        for (int i = 0; i < n; i++){
            printf("%d", perm[i]);
        }
        putchar('\n');
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            perm[pos] = i;
            used[i] = true;
            permutation1(pos + 1, n);
            used[i] = false;
        }
    }
    return;
}

int perm2[MAX_N];

void permutation2(int n){
    for (int i = 0; i < n; i++){
        perm2[i] = i;
    }
    do {
        for (int i = 0; i < n; i++){
            printf("%d", perm2[i]);
        }
        putchar('\n');
    } while (std::next_permutation(perm2, perm2 + n));
    return;
}



int main(void) {
    int pos, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &perm[i]);
        getchar();
    }
    pos = 0;
    permutation2(n);
    return 0;
}