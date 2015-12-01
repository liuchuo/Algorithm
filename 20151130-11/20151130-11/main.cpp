//algorithm中的lower_bound
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[5] = {1 ,2, 5, 7, 3};
    sort(a, a+5);
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    int p = upper_bound(a, a + 5, 3) - a;
        cout << p + 1 << endl;
    return 0;
}
/*
lower_bound(a, a + 5, 3) - a;
指向键值>= key的第一个元素。
upper_bound指向键值> key的第一个元素。
*/