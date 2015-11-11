//问题描述
//　　给定n个十六进制正整数，输出它们对应的八进制数。
//
//输入格式
//　　输入的第一行为一个正整数n （1<=n<=10）。
//　　接下来n行，每行一个由0~9、大写字母A~F组成的字符串，表示要转换的十六进制正整数，每个十六进制数长度不超过100000。
//
//输出格式
//　　输出n行，每行为输入对应的八进制正整数。
//
//　　【注意】
//　　输入的十六进制数不会有前导0，比如012A。
//　　输出的八进制数也不能有前导0。
#include <iostream>
using namespace std;

int to10(string s);
int to8(int b);

int main() {
    int n;
    cin >> n;
    string s;
    int d[10];
    for (int i = 0; i < n; i++) {
        cin >> s;
        d[i] = to8(to10(s));
    }
    for (int i = 0; i < n; i++) {
        cout << d[i] << endl;
    }
    
    return 0;
}

int to10(string s) {
    int len = s.length();
    int sum = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'F')
            sum = sum * 16 + s[i] - 'A' + 10;
        else
            sum = sum * 16 + s[i] - '0';
    }
    return sum;
}

int to8(int b) {
    int i = 0;
    int a[100];
    int sum = 0;
    if (b == 0)
        return 0;
    else {
        while (b != 0) {
            a[i++] = b % 8;
            b = b / 8;
        }
        for (int j = i - 1; j >= 0; j--)
            sum = sum * 10 + a[j];
        return sum;
    }
}
