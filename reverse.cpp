#include <iostream>
#include <algorithm> 
using namespace std;
int main() {
    int a[10] = {987, 654, 32, 1, 0};
    reverse(a, a + 10);
    reverse(begin(a), end(a));
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    return 0;
}