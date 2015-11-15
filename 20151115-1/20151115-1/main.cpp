////算法提高 6-17复数四则运算
//设计复数库，实现基本的复数加减乘除运算。
//　　输入时只需分别键入实部和虚部，以空格分割，两个复数之间用运算符分隔；
//输出时按a+bi的格式在屏幕上打印结果。参加样例输入和样例输出。
//　　注意考虑特殊情况，无法计算时输出字符串"error"。
//样例输入
//2 4 * -3 2
//样例输出
//-14-8i
//样例输入
//3 -2 + -1 3
//样例输出
//2+1i

#include <iostream>
using namespace std;

void add(int a, int b, int m, int n);
void min(int a, int b, int m, int n);
void multi(int a, int b, int m, int n);
void div1(int a, int b, int m, int n);

int main() {
    int a,b,m,n;
    char c;
    cin >> a >> b;
    cin >> c;
    cin >> m >> n;
    switch(c) {
        case '+': add(a, b, m, n); break;
        case '-': min(a, b, m, n); break;
        case '*': multi(a, b, m, n); break;
        case '/': div1(a, b, m, n); break;
    }
    return 0;
}

void add(int a, int b, int m, int n) {
    int l, r;
    l = a + m;
    r = b + n;
    if (l != 0){
        if (r != 0) {
            if (r > 0)
                cout << l << "+" << r << "i";
            else
                cout << l << r << "i";
        }
        else {
            cout << l;
        }
    }
    else {
        if (r != 0) {
            cout << r << "i";
        }
        else {
            cout << 0;
        }
    }
}

void min(int a, int b, int m, int n) {
    int l, r;
    l = a - m;
    r = b - n;
    if (l != 0) {
        if (r != 0) {
            if (r > 0)
                cout << l << "+" << r << "i";
            else
                cout << l << r << "i";
        }
        else {
            cout << l;
        }
    }
    else {
        if (r != 0) {
            cout << r << "i";
        }
        else {
            cout << 0;
        }
    }
}

void multi(int a, int b, int m, int n) {
    int l, r;
    l = a * m - b * n;
    r = a * n + b * m;
    if (l != 0) {
        if (r != 0) {
            if (r > 0)
                cout << l << "+" << r << "i";
            else
                cout << l << r << "i";
        }
        else {
            cout << l;
        }
    }
    else {
        if (r != 0) {
            cout << r << "i";
        }
        else {
            cout << 0;
        }
    }
}

void div1(int a, int b, int m, int n) {
    if (m == 0 && n == 0)
        cout << "error";
    else if (((a * m + b * n) % (m * m + n * n)) != 0 ||((b * m - a * n) % (m * m + n * n)) != 0) {
        cout << "error";
    } else {
        int l, r;
        l = (a * m + b * n) / (m * m + n * n);
        r = (b * m - a * n) / (m * m + n * n);
        if (l != 0) {
            if (r != 0) {
                if (r > 0)
                    cout << l << "+" << r << "i";
                else
                    cout << l << r << "i";
            }
            else {
                cout << l;
            }
        }
        else {
            if (r != 0) {
                cout << r << "i";
            }
            else {
                cout << 0;
            }
        }
    }
}
