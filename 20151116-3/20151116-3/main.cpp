////1033. 旧键盘打字(20)
//旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出
//应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？
//输入格式：
//输入在2行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键
//以大写给出；每段文字是不超过 10^5 个字符的串。可用的字符包括字母[a-z, A-Z]、
//数字0-9、以及下划线“_”（代表空格）、“,”、“.”、“-”、“+”（代表上档键）。
//题目保证第2行输入的文字串非空。
//注意：如果上档键坏掉了，那么大写的英文字母无法被打出。
//输出格式：
//在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。
//输入样例：
//7+IE.
//7_This_is_a_test.
//输出样例：
//_hs_s_a_tst

#include <iostream>
#include <string>
using namespace std;
int main() {
    string a;
    string b;
    cin >> a;
    cin >> b;
    int lena = a.length();
    int lenb = b.length();
    for (int i = 0; i < lenb; i++) {
        for (int j = 0; j < lena; j++) {
            if (b[i] == a[j]) {
                b[i] = '#';
            }
            if (a[j] >= 'A' && a[j] <= 'Z') {
                if (b[i] == (a[j] + 32)) {
                    b[i] = '#';
                }
            }
        }
    }
    int flag = 0;
    for (int i = 0; i < lena; i++) {
        if (a[i] == '+') {
            flag = 1;
        }
    }
    if (flag == 1) {
        for (int i = 0; i < lenb; i++) {
            if (b[i] >= 'A' && b[i] <= 'Z')
                b[i] = '#';
        }
    }
    int flag2 = 0;
    for (int i = 0; i < lenb; i++) {
        if (b[i] != '#') {
            cout << b[i];
            flag2 = 1;
        }
    }
    if (flag2 == 0) {
        cout << endl;
    }
    return 0;
}
