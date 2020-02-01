#include <cstdio>

int N, M;

void dfs(int x, int y, char field[][100]) {

    field[x][y] = '.';

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {

            int nx = x + dx, ny = y + dy;

            if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W') dfs(nx, ny, field);
        }
    }
    return;
}

int main() {
    int res = 0;

    scanf("%d", &N);
    scanf("%d", &M);
    puts("---");
    getchar();
    char field[100][100];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%c", &field[i][j]);
        }
        getchar();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (field[i][j] == 'W') {
                dfs(i, j, field);
                res++;
            }
        }
    }
    printf("%d\n", res);
    return 0;

}