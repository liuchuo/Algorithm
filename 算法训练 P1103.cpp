算法训练 P1103  
时间限制：1.0s   内存限制：256.0MB
提交此题    
　　﻿
　　编程实现两个复数的运算。设有两个复数 和 ，则他们的运算公式为：

　　要求：（1）定义一个结构体类型来描述复数。
　　（2）复数之间的加法、减法、乘法和除法分别用不用的函数来实现。
　　（3）必须使用结构体指针的方法把函数的计算结果返回。
　　说明：用户输入：运算符号(+,-,*,/) a b c d.
　　输出：a+bi，输出时不管a,b是小于0或等于0都按该格式输出，输出时a,b都保留两位。

输入：
　　- 2.5 3.6 1.5 4.9
输出：
　　1.00+-1.30i

#include <iostream>
#include <cstdio>
using namespace std;
struct node {
    float a;
    float b;
};

char t;

struct node m, n, p, *q;

struct node * add() {
    p.a = m.a + n.a;
    p.b = m.b + n.b;
    q = &p;
    return q;
}

struct node * minu() {
    p.a = m.a - n.a;
    p.b = m.b - n.b;
    q = &p;
    return q;
}

struct node * multi() {
    p.a = m.a * n.a - m.b * n.b;
    p.b = m.a * n.b + m.b * n.a;
    q = &p;
    return q;
}

struct node * div() {
    p.a = (m.a * n.a + m.b * n.b) / (n.a * n.a + n.b * n.b);
    p.b = (m.b * n.a - m.a * n.b) / (n.a * n.a + n.b * n.b);
    q = &p;
    return q;
}

int main() {
    scanf("%c %f %f %f %f", &t, &m.a, &m.b, &n.a, &n.b);
    if(t == '+')
        add();
    if(t == '-')
        minu();
    if(t == '*')
        multi();
    if(t == '/')
        div();
    printf("%.2f+%.2fi", q->a, q->b);
    return 0;
}