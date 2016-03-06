算法训练 字串统计  
时间限制：1.0s   内存限制：512.0MB
提交此题    
问题描述
　　给定一个长度为n的字符串S，还有一个数字L，统计长度大于等于L的出现次数最多的子串
（不同的出现可以相交），如果有多个，输出最长的，如果仍然有多个，输出第一次出现最早的。
输入格式
　　第一行一个数字L。
　　第二行是字符串S。
　　L大于0，且不超过S的长度。
输出格式
　　一行，题目要求的字符串。

　　输入样例1：
　　4
　　bbaabbaaaaa

　　输出样例1：
　　bbaa

　　输入样例2：
　　2
　　bbaabbaaaaa

　　输出样例2：
　　aa
数据规模和约定
　　n<=60
　　S中所有字符都是小写英文字母。
提示
　　枚举所有可能的子串，统计出现次数，找出符合条件的那个

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int num;
    cin >> num;
    string a;
    cin >> a;
    vector<string> v;
    int len = a.length();
    for (int i = num; i <= len; i++) {
        for (int j = 0; j <= len - i; j++) {
            v.push_back(a.substr(j, i));
        }
    }
    
    int max = 0;
    int k = 0;
    int *book = new int [v.size()];
    for (int i = 0; i <= v.size() - 1; i++)
        book[i] = 0;
    for (int i = 0; i <= v.size() - 1; i++) {
        for (int j = 0; j <= v.size() - 1; j++) {
            if (i != j && v[i] == v[j])
                book[i]++;
        }
    }
    
    for (int i = 0; i <= v.size() - 1; i++) {
        if (book[i] > max || (book[i] == max && v[k].length() < v[i].length())) {
            k = i;
            max = book[i];
        }
    }
    cout << v[k];
    return 0;
}

