//算法提高 三个整数的排序  
时间限制：1.0s   内存限制：256.0MB
提交此题    
问题描述
　　﻿输入三个数，比较其大小，并从大到小输出。
输入格式
　　一行三个整数。
输出格式
　　一行三个整数，从大到小排序。
样例输入
33 88 77
样例输出
88 77 33

#include <iostream>
using namespace std;
int main() {
    int a, b, c, t;
    cin >> a >> b >> c;
    if (a < b) {
        t = a;
        a = b;
        b = t;
    }
    if (b < c) {
        t = b;
        b = c;
        c = t;
    }
    if (a < b) {
        t = a;
        a = b;
        b = t;
    }
    cout << a << " " << b << " " << c;
    return 0;
}