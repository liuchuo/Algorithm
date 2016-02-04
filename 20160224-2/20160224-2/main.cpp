/*
算法训练 Tricky and Clever Password
时间限制：2.0s   内存限制：256.0MB
问题描述
　　在年轻的时候，我们故事中的英雄——国王 Copa——他的私人数据并不是完全安全地隐蔽。对他来说是，这不可接受的。因此，他发明了一种密码，好记又难以破解。后来，他才知道这种密码是一个长度为奇数的回文串。
　　Copa 害怕忘记密码，所以他决定把密码写在一张纸上。他发现这样保存密码不安全，于是他决定按下述方法加密密码：他选定一个整数 X ，保证 X 不小于 0 ，且 2X 严格小于串长度。然后他把密码分成 3 段，最前面的 X 个字符为一段，最后面的 X 个字符为一段，剩余的字符为一段。不妨把这三段依次称之为 prefix, suffix, middle 。显然， middle 的长度为一个大于 0 的奇数，且 prefix 、 suffix 的长度相等。他加密后的密码即为 A + prefix + B + middle + C + suffix ，其中 A 、 B 、 C 是三个由 Copa 选定的字符串，且都有可能为空， + 表示字符串相连。
　　许多年过去了。Copa 昨天找到了当年写下加密后字符串的那张纸。但是，Copa 把原密码、A、B、C 都忘了。现在，他请你找一个尽量长的密码，使得这个密码有可能被当年的 Copa 发明、加密并写下。
输入格式
　　输入包含一个只含有小写拉丁字母的字符串，长度在 1 到 10^5 之内。
输出格式
　　第一行包含一个整数 k ，表示你找到的原密码分成的 3 个部分中有多少个非空字符串。显然 k in {1, 3} 。接下来 k 行，每行 2 个用空格分开的整数 x_i l_i ，表示这一部分的起始位置和长度。要求输出的 x_i 递增。
　　起始位置 x_i 应该在 1 到加密后的字符串长度之间。 l_i 必须是正整数，因为你只要输出非空部分的信息。 middle 的长度必须为奇数。
　　如果有多组答案，任意一组即可。提示：你要最大化的是输出的 l_i 的总和，而不是 k 。
样例输入
abacaba
样例输出
1
1 7
样例输入
axbya
样例输出
3
1 1
2 1
5 1
样例输入
xabyczba
样例输出
3
2 2
4 1
7 2
数据规模和约定
　　对于 10% 的数据： n <= 10
　　对于 30% 的数据： n <= 100
　　对于 100% 的数据： n <= 100000
　　存在 20% 的数据，输出文件第一行为 1 。
*/
#include <iostream>
#include <string>
using namespace std;
void func(int leng, char *s, int t2);

int main() {
    string str;
    cin >> str;
    int t1 = 1;
    int t2 = 1;
    int p1 = 0;
    int len = str.length();
    int p2 = len - 1;
    int k = 1;
    for(int i = 0; i < len / 2; i++) {
        if(str[i] != str[len - 1 - i])
            k = 3;
    }
    if (k == 1 && len % 2 == 0)
        k = 3;
    while(str[p1] != str[len - 1] && p1 < len - 2) {
        p1++;
        t1++;
        t2++;
    }
    int flag = 0;
    while(str[p1] == str[p2] && p1 < p2 - 1) {
        p1++;
        p2--;
        t2++;
        flag = 1;
    }
    if(flag == 0) {
        k = 1;
    }
    cout << k << endl;
    if(k == 1 && flag == 1) {
        cout << 1 << " " << len << endl;
        return 0;
    } else if (k == 1) {
        cout << len << " " << 1 << endl;
        return 0;
    }
    cout << t1 << " " << t2 - t1 << endl;
    char s[len - 2 * t2 + t1 + 1];
    int leng = len - 2 * t2 + t1 + 1;
    int j = 0;
    for(int i = t2 - 1; i <= len - 1 - t2 + t1; i++) {
        s[j++] = str[i];
    }
    func(leng, s, t2);
    cout << len - t2 + t1 + 1 << " " << t2 - t1 << endl;
    return 0;
}

void func(int leng, char *s, int t2) {
    int temp = 0;
    int max = 0;
    int cur = 0;
    for(int i = 1; i <= leng - 2; i++) {
        int j = i;
        int k = i;
        temp = 0;
        while(s[--j] == s[++k] && j >= 0 && k <= leng - 1)
            temp++;
        if (temp > max) {
            max = temp;
            cur = i;
        }
    }
    cout << cur - max + t2 << " " << 2 * max + 1 << endl;
}