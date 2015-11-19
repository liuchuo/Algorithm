#include <iostream>
#include <algorithm>

using namespace std;

int cmp(int a, int b) {
    return a < b;
}

int main() {
    int n;
    cin >> n;
    int *a = new int [n];
    int *b = new int [n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int t = 0;
    int flag;
    for (int i = 0; i < n; i++) {
        flag = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] > a[i]) {
                flag = 0;
                break;
            }
        }
        for (int k = i + 1; k < n; k++) {
            if (a[k] < a[i]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            b[t++] = a[i];
        }
        
    }
    sort(b, b + t, cmp);
    if (t != 0) {
        cout << t << endl;
    } else {
        cout << 0;
    }
    for (int i = 0; i < t - 1; i++) {
        cout << b[i] << " ";
    }
    if (t != 0) {
        cout << b[t - 1];
    }
    delete [] a;
    delete [] b;
    return 0;
}