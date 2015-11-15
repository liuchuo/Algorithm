////算法提高 c++_ch02_01
//编写一个程序，利用强制类型转换打印元音字母大小写10种形式的ASCII码。
//　　输出的顺序为：大写的字母A，E，I，O，U的ASCII码，小写的字母a，e，i，o，u的ASCII码
//所有的ASCII码都用十进制表示.输出10行,每行一个ASCII码，最后输出一个空行。
#include <iostream>
using namespace std;
int main() {
    char c[10] = {'A','E','I','O','U','a','e','i','o','u'};
    for (int i = 0; i < 10; i++)
        cout << static_cast<int> (c[i]) << endl;
    return 0;
}
