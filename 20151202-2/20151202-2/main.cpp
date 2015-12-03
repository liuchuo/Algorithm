////deque
//deque全名double-ended queue,双端队列。
//头文件要写#include <deque>
/*
a.push_front(0);//在头部加入数据0
a.push_back(11);//在尾部加入数据11
a.pop_front();//在头部删除数据
a.pop_back();//在尾部删除数据
a.resize(num);//重新指定队列的长度
a.size() //返回容器中实际数据个数
a.max_size() //返回容器中最大数据的数量
*/
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    deque<int> a(10); //创建一个有10个元素双端队列a,初始值都为0
    
    //给deque赋值
    for (int i = 0; i < a.size(); i++) {
        a[i] = i + 1;
    }
    
    //输出deque中的数据
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    //在头尾加入新数据
    cout << "在头部加入数据0：" << endl;
    a.push_front(0);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    cout << "在尾部加入数据11：" << endl;
    a.push_back(11);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    //在头尾删除数据
    cout << "在头部删除数据: " << endl;
    a.pop_front();
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "在尾部删除数据: " << endl;
    a.pop_back();
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    //返回容器中实际数据个数
    cout << "a.size() = " << a.size() << endl;
    
    //重新指定队列的长度
    a.resize(11);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    //判断队列是否为空
    cout << "a.empty() = " << a.empty() << endl;
    
    //返回容器中最大数据的数量
    cout << "a.max_size() = " << a.max_size() << endl;
    
    return 0;
}