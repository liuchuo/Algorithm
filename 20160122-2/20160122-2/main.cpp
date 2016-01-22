////算法提高 排列数-用递归方法求全排列
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
//(输出0123456789的全排列中的第n个数)
//


#include <iostream>
using namespace std;

int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void func(long long n, int k) {
    static long long count;
    if (k == 9) {
        count++;
        if (count == n) {
            for (int i = 0; i <= 9; i++)
                cout << a[i];
        }
    } else {
        for (int i = k; i <= 9; i++) {
            swap(a[i], a[k]);
            func(n, k + 1);
            swap(a[i], a[k]);
        }
    }
}

int main() {
    long long n;
    cin >> n;
    func(n, 0);
    return 0;
}