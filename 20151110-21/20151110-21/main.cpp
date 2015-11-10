//问题描述
//　　123321是一个非常特殊的数，它从左边读和从右边读是一样的。
//　　输入一个正整数n， 编程求所有这样的五位和六位十进制数，满足各位数字之和等于n 。
//输入格式
//　　输入一行，包含一个正整数n。
//输出格式
//　　按从小到大的顺序输出满足条件的整数，每个整数占一行。
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i1 = 1; i1 <= 9; i1++)
        for (int i2 = 0; i2 <= 9; i2++)
            for (int i3 = 0; i3 <= 9; i3++) {
                if ((i1 + i2 + i3 + i2 + i1) == n)
                    cout << i1 << i2 << i3 << i2 << i1 << endl;
            }
    for (int i1 = 1; i1 <= 9; i1++)
        for (int i2 = 0; i2 <= 9; i2++)
            for (int i3 = 0; i3 <= 9; i3++) {
                if ((i1 + i2 + i3 + i3 + i2 + i1) == n)
                    cout << i1 << i2 << i3 << i3 << i2 << i1 << endl;
            }
    return 0;
}