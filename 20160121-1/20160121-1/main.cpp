////
//算法提高 排列数
//时间限制：1.0s   内存限制：256.0MB
//提交此题
//问题描述
//　　0、1、2三个数字的全排列有六种，按照字母序排列如下：
//　　012、021、102、120、201、210
//　　输入一个数n
//　　求0~9十个数的全排列中的第n个（第1个为0123456789）。
//输入格式
//　　一行，包含一个整数n
//输出格式
//　　一行，包含一组10个数字的全排列
//样例输入
//1
//样例输出
//0123456789
//数据规模和约定
//　　0 < n <= 10!

#include <iostream>
using namespace std;
int main() {
    int count = 0, n;
    cin >> n;
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                for (int l = 0; l <= 9; l++)
                    for (int m = 0; m <= 9; m++)
                        for (int o = 0; o <= 9; o++)
                            for (int p = 0; p <= 9; p++)
                                for (int q = 0; q <= 9; q++)
                                    for (int r = 0; r <= 9; r++)
                                        for (int s = 0; s <= 9; s++) {
                                            if (i != j && i != k && i != l && i != m && i != o && i != p &&
                                                i != q && i != r && i != s && j != k && j != l && j != m &&
                                                j != o && j != p && j != q && j != r && j != s && k != l &&
                                                k != m && k != o && k != p && k != q && k != r && k != s &&
                                                l != m && l != o && l != p && l != q && l != r && l != s &&
                                                m != o && m != p && m != q && m != r && m != s && o != p &&
                                                o != q && o != r && o != s && p != q && p != r && p != s &&
                                                q != r && q != s && r != s) {
                                                count++;
                                                if (count == n) {
                                                    cout << i << j << k << l << m << o << p << q << r << s;
                                                    return 0;
                                                }
                                            }
                                        }
    return 0;
}
