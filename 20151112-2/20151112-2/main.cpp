////算法训练 前缀表达式
//问题描述
//　　编写一个程序，以字符串方式输入一个前缀表达式，然后计算它的值。
//输入格式为：“运算符 对象1 对象2”，其中，运算符为“+”（加法）、“-”（减法）、
//“*”（乘法）或“/”（除法），运算对象为不超过10的整数，它们之间用一个空格隔开。
//要求：对于加、减、乘、除这四种运算，分别设计相应的函数来实现。
//　　输入格式：输入只有一行，即一个前缀表达式字符串。
//　　输出格式：输出相应的计算结果（如果是除法，直接采用c语言的“/”运算符，结果为整数）。
//　　输入输出样例
//样例输入
//+ 5 2
//样例输出
//7

#include <iostream>
#include <string>
using namespace std;
void add(int a, int b) {cout << a + b;}
void min(int a, int b) {cout << a - b;}
void mul(int a, int b) {cout << a * b;}
void div1(int a, int b) {cout << a / b;}

int main() {
    string s;
    int a, b;
    getline(cin, s);
    if (s[3] == ' ') {
        a = s[2] - '0';
        if (s[5] == '\0') {
            b = s[4] - '0';
        }
        else {
            b = 10;
        }
    }
    else {
        a = 10;
        if (s[6] == '\0') {
            b = s[5] - '0';
        }
        else {
            b = 10;
        }
    }
    switch(s[0]) {
        case '+':add(a, b);break;
        case '-':min(a, b);break;
        case '*':mul(a, b);break;
        case '/':div1(a, b);break;
    }
    return 0;
}
