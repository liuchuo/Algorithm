// 问题描述
// 给定圆的半径r，求圆的面积。
// 输入格式
// 输入包含一个整数r，表示圆的半径。
// 输出格式
// 输出一行，包含一个实数，四舍五入保留小数点后7位，表示圆的面积。
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int r;
    cin >> r;
    double s;
    double PI = atan(1.0) * 4;
    s =  PI * r * r;
    printf("%.7lf",s);
    return 0;
}
