//memset memcpy
#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int a[10];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
        a[i] = i;
    }
    cout << endl;
    int b[10];
    for (int i = 0; i < 10; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    memcpy(b, a, sizeof(int) * 5);
    for (int i = 0; i < 10; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}