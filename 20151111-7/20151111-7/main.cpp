////图形显示
//问题描述
//　　编写一个程序，首先输入一个整数，例如5，然后在屏幕上显示如下的图形（5表示行数）：
//　　* * * * *
//　　* * * *
//　　* * *
//　　* *
//　　*
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++) {
            cout << "* ";
        }
        cout << "*" << endl;
    }
    return 0;
}
