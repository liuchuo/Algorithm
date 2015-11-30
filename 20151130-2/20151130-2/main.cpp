//while (scanf("%d", 7x) == 1)
#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    int max = x;
    int min = x;
    while (cin >> x) {
        if (max < x)
            max = x;
        if (min > x)
            min = x;
    }
    cout << max << min;
    return 0;
}




