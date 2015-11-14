////算法提高 十进制数转八进制数
//编写函数，其功能为把一个十进制数转换为其对应的八进制数。程序读入一个十进制数，
//调用该函数实现数制转换后，输出对应的八进制数。
//样例输入
//9274
//样例输出
//22072
//样例输入
//18
//样例输出
//22

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n == 0)
        return 0;
    int b[30];
    int i = 0;
    while (n != 0) {
        b[i++] = n % 8;
        n = n / 8;
    }
    for (int j = i - 1; j >=0; j--) {
        cout << b[j];
    }
    return 0;
}
