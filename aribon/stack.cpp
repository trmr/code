#include <stack>
#include <cstdio>

int main() {
    std::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    printf("%d\n", s.top());
    s.pop();
    printf("%d\n", s.top());
    s.pop();
    printf("%d\n", s.top());
    s.pop();

    return 0;
}