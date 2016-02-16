算法提高 P1001  
时间限制：1.0s   内存限制：256.0MB 
　　当两个比较大的整数相乘时，可能会出现数据溢出的情形。为避免溢出，可以采用字符串的方法来实现两个大数之间的乘法。
具体来说，首先以字符串的形式输入两个整数，每个整数的长度不会超过8位，然后把它们相乘的结果存储在另一个字符串当中（长度不会超过16位），
最后把这个字符串打印出来。例如，假设用户输入为：62773417和12345678，则输出结果为：774980393241726.
输入：
　　62773417 12345678
输出：
　　774980393241726
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    int lena = a.length();
    int lenb = b.length();
    char d[20][20];
    char c[20];
    for (int i = 0; i <= 19; i++) {
        for (int j = 0; j <= 19; j++) {
            d[i][j] = '0';
        }
        c[i] = '0';
    }
    
    int temp = 0;
    int k = 0;
    int cou = 0;
    int t = 0;
    for (int i = lenb - 1; i >= 0; i--) {
        k = 0;
        for (int j = lena - 1; j >= 0; j--) {
            t = ((b[i] - '0') * (a[j] - '0'));
            temp = temp + t * pow(10, k++);
        }
        k = 0;
        while(temp != 0) {
            d[cou][k++] = (temp % 10) + '0';
            temp = temp / 10;
        }
        cou++;
    }
    
    for (int i = 0; i <= 18; i++) {
        for (int j = 0; j <= i; j++) {
            c[i] = (c[i] - '0' + d[j][i - j] - '0') % 10 + '0';
            temp = temp + (d[j][i - j] - '0');
        }
        temp = temp / 10;
        c[i + 1] = temp + '0';
    }
    
    int flag = 0;
    for (int i = 19; i >= 0; i--) {
        if (c[i] != '0') {
            flag = i;
            break;
        }
    }
    for (int i = flag; i >= 0; i--) {
        cout << c[i];
    }
    return 0;
}