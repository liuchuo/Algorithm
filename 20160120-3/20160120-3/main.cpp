//
//
//memset是计算机中C/C++语言函数。将s所指向的某一块内存中的前n个 字节的内容全部设置为ch指定的ASCII值， 第一个值为指定的内存地址，块的大小由第三个参数指定，这个函数通常为新申请的内存做初始化工作， 其返回值为指向s的指针。
//数字三角形：第三种方法，记忆化搜索（递归函数，o(n^2）)
#include <iostream>
#include <algorithm>
#include <cstring>
int f(int i, int j);
int a[101][101];
int d[101][101];
int n;
using namespace std;
int main() {
    memset(d, -1, sizeof(d));
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
    cout << f(1, 1);
    return 0;
}

int f(int i, int j) {
    if (d[i][j] >= 0)
        return d[i][j];
    if (i == n)
        return a[i][j];
    else
        return d[i][j] = a[i][j] + max(f(i + 1, j), f(i + 1, j + 1));
}
