/*
 不定长数组：vector
 vector是一个模板类 所以使用时要用vector<int> a 或者 vector<double> b这样的方式来声明一个vector
 vector<int>是一个类似于int a[]的整数数组，而vector<string>是一个类似于string a[]的字符串数组
 clear()清空
 resize()改变大小
 push_back()在尾部添加元素
 pop_back()在尾部删除元素
 empty()测试是否为空
 vector之间可以直接赋值或者作为函数的返回值
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a;
    int t;
    for (int i = 0; i < 10; i++) {
        cin >> t;
        a.push_back(t);
    }
    vector<int> b;
    b = a;
    cout << "print b: 直接赋值" << endl;
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    cout << "a.size() = " << a.size() << endl;
    
    cout << "print1:" << endl;
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    a.resize(11);
    cout << "a.size() = after resize(11) :" << a.size() << endl;
    cout << "print2 after resize(11):" << endl;
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    a.push_back(22);
    cout << "print3 after push_back(22):" << endl;
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    a.pop_back();
    cout << "a.size() = after pop_back() :" << a.size() << endl;
    cout << "print4 after pop_back():" << endl;
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "a.empty()?:" << a.empty() << endl;
    a.clear();
    cout << "a.size() = after a.clear() :" << a.size() << endl;
    cout << "print5 after a.clear():" << endl;
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}