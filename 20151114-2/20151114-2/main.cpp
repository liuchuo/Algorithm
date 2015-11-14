////算法训练 动态数组使用
//从键盘读入n个整数，使用动态数组存储所读入的整数，
//并计算它们的和与平均值分别输出。
//要求尽可能使用函数实现程序代码。平均值为小数的只保留其整数部分。
//样例输入:
//5
//3 4 0 0 2
//样例输出:
//9  1
//样例输入:
//7
//3 2 7 5 2 9 1
//样例输出:
//29  4

#include <iostream>
using namespace std;
int add(int arr[], int n) {
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    int *a = new int [n];
    for (int i = 0;i < n; i++) {
        cin >> a[i];
    }
    cout << add(a, n) << " ";
    int aver = 0;
    aver = add(a, n) / n;
    cout << aver;
    delete [] a;
}
