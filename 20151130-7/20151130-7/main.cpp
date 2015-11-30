//C中的传地址swap
#include <iostream>
using namespace std;
void swap1(int *a, int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
int main() {
    int a = 1;
    int b = 9;
    swap1(&a, &b);
    cout << "a = " << a  << endl;
    cout << "b = " << b << endl;
    return 0;
}
