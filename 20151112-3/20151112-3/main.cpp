////算法训练 Anagrams问题
//问题描述
//　　Anagrams指的是具有如下特性的两个单词：在这两个单词当中，每一个英文字母（不区分大小写）所出现的次数都是相同的。例如，“Unclear”和“Nuclear”、“Rimon”和“MinOR”都是Anagrams。编写一个程序，输入两个单词，然后判断一下，这两个单词是否是Anagrams。每一个单词的长度不会超过80个字符，而且是大小写无关的。
//　　输入格式：输入有两行，分别为两个单词。
//　　输出格式：输出只有一个字母Y或N，分别表示Yes和No。
//　　输入输出样例
//样例输入
//Unclear
//Nuclear
//样例输出
//Y

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    int a[26] = {0};
    int b[26] = {0};
    int flag = 1;
    string m, n;
    cin >> m;
    cin >> n;
    int lenm = m.length();
    int lenn = n.length();
    if (lenm != lenn) {
        cout << 'N';
        return 0;
    }
    for (int i = 0; i < lenm; i++) {
        m[i] = toupper(m[i]);
        n[i] = toupper(n[i]);
    }
    for (int i = 0; i < lenm; i++) {
        a[m[i] - 'A']++;
        b[n[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i])
            flag = 0;
    }
    if (flag == 0)
        cout << 'N';
    else
        cout << 'Y';
    return 0;
}
