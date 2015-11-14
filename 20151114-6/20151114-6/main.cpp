////算法训练 寻找数组中最大值
//问题描述
//　　对于给定整数数组a[],寻找其中最大值，并返回下标。
//输入格式
//　　整数数组a[],数组元素个数小于1等于100。输出数据分作两行：
//第一行只有一个数，表示数组元素个数；第二行为数组的各个元素。
//输出格式
//　　输出最大值，及其下标
//样例输入
//3
//3 2 1
//样例输出
//3 0

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int *arr = new int [n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int max = arr[0];
    int t = 0;
    for (int i = 1; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
            t = i;
        }
    }
    cout << max << " " << t;
    return 0;
}
