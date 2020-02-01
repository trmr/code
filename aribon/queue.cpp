#include <queue>
#include <cstdio>

int main() {
    std::queue<int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    printf("%d\n", que.front());
    que.pop();
    printf("%d\n", que.front());
    que.pop();
    printf("%d\n", que.front());
    que.pop();
    return 0;
}