#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int main() {
    int aiTable[5] = { 3, 2, 6, -2, 2 };            // 配列を用意する。
    sort(aiTable, aiTable + 5, greater<int>());  // プレディケート greater で逆順にソートする。
    {for (int iIndex = 0; iIndex < 5; iIndex++) {
        cout << aiTable[iIndex] << ", ";            // 結果をプリントしてみる。
    }}
    return 0;
}