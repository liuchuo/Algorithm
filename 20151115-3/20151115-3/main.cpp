////算法提高 约数个数
//输入一个正整数N
//样例输入
//12
//样例输出
//6
//样例说明
//　　12的约数包括：1,2,3,4,6,12。共6个

#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0)
            count++;
    }
    cout << count;
}
