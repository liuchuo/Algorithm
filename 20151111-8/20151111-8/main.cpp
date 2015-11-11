////算法训练-排序
//问题描述
//　　编写一个程序，输入3个整数，然后程序将对这三个整数按照从大到小进行排列。
//　　输入格式：输入只有一行，即三个整数，中间用空格隔开。
//　　输出格式：输出只有一行，即排序后的结果。
//　　输入输出样例
//样例输入
//9 2 30
//样例输出
//30 9 2

#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int t;
    if (a < b) {
        t = a;
        a = b;
        b = t;
    }
    if (a < c) {
        t = a;
        a = c;
        c = t;
    }
    if (b < c) {
        t = b;
        b = c;
        c = t;
    }
    cout << a << " " << b << " " << c;
    return 0;
}
