////  算法训练 数字三角形(动态规划)
//时间限制：1.0s   内存限制：256.0MB
//问题描述
//　　图示出了一个数字三角形。 请编一个程序计算从顶至底的某处的一条路
//　　径，使该路径所经过的数字的总和最大。
//　　●每一步可沿左斜线向下或右斜线向下走；
//　　●1＜三角形行数≤100；
//　　●三角形中的数字为整数0，1，…99；
//输入格式
//　　文件中首先读到的是三角形的行数。
//　　接下来描述整个三角形
//输出格式
//　　最大总和（整数）
//样例输入
//5
//7
//3 8
//8 1 0
//2 7 4 4
//4 5 2 6 5
//样例输出
//30
//
//三种方法：递归、递推、记忆化搜索
//第一种方法，递归：O(2^n)
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int d(int i, int j);
int n;
int a[101][101];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
    cout << d(1, 1);
    return 0;
}

int d(int i, int j) {
    if (i == n)
        return a[i][j];
    else
        return a[i][j] + max(d(i + 1, j), d(i + 1, j + 1));
}
