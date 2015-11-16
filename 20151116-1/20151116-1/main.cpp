//1010. 一元多项式求导 (25)
//设计函数求一元多项式的导数。（注：xn（n为整数）的一阶导数为n*xn-1。）
//输入格式：以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。
//数字间以空格分隔。
//输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，
//但结尾不能有多余空格。注意“零多项式”的指数和系数都是0，但是表示为“0 0”。
//输入样例：
//3 4 -5 2 6 1 -2 0
//输出样例：
//12 3 -10 1 6 0

#include <iostream>
using namespace std;
int main() {
    int a[2000] = {0};
    int count = 0;
    for (int i = 0; i < 2000; i++) {
        cin >> a[i];
        count++;
        if(getchar() == '\n')
            break;
    }
    int b[2000];
    if (count == 2 && a[1] != 0) {
        b[0] = a[0] * a[1];
        b[1] = a[1] - 1;
    cout << b[0] << " " << b[1];
    return 0;
    }
    if (count == 2 && a[1] == 0 && a[0] != 0) {
        cout << 0 << " " << 0;
        return 0;
    }
    if (a[0] == 0 && a[1] == 0) {
        cout << 0 << " " << 0;
        return 0;
    }
    
    for (int i = 0; i < count; i++) {
        if (i % 2 == 0) {
            b[i] = a[i] * a[i + 1];
        }
        else {
            b[i] = a[i] - 1;
        }
    }
    
    for (int i = 0; i < count - 3; i++) {
        cout << b[i] << " ";
    }
    cout << b[count - 2];
    
    if (b[count - 1] != -1) {
        cout << " " << b[count - 2] << " " << b[count - 1];
    }
    return 0;
}
