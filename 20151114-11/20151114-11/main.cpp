////算法提高 第二大整数
//问题描述
//　　编写一个程序，读入一组整数（不超过20个），当用户输入0时，表示输入结束。
//然后程序将从这组整数中，把第二大的那个整数找出来，并把它打印出来。
//说明：（1）0表示输入结束，它本身并不计入这组整数中。（2）在这组整数中，既有正数，
//也可能有负数。（3）这组整数的个数不少于2个。
//　　输入格式：输入只有一行，包括若干个整数，中间用空格隔开，最后一个整数为0。
//　　输出格式：输出第二大的那个整数。
//　　输入输出样例
//样例输入
//5 8 -12 7 0
//样例输出
//7

#include <iostream>
#include <algorithm>
using namespace std;

int cmp(int a, int b) {
    return a > b;
}
int main() {
    int a[20];
    int count = 0;
    for (int i = 0; i < 20; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            count = i;
            break;
        }
    }
    sort(a, a + count,cmp);
    cout << a[1];
    return 0;
}
