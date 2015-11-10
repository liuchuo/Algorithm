// 问题描述
// 求1+2+3+...+n的值。
// 输入格式
// 输入包括一个整数n。
// 输出格式
// 输出一行，包括一个整数，表示1+2+3+...+n的值。
#include <iostream>
int main() {
    using namespace std;
    long long n;
    cin >> n;
    long long result;
    result = (1 + n) * n / 2;
    printf("%I64d",result);
    return 0;
}
