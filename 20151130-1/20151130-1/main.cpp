//clock() CLOCKS_PER_SEC
#include <iostream>
#include <time.h>
using namespace std;

int main() {
    const int MOD = 1000000;
    clock_t start, finish;
    int n, s = 0;
    cin >> n;
    start = clock();
    for (int i = 1; i <= n; i++) {
        int factorial = 1;
        for (int j = 1; j <= i; j++) {
            factorial = (factorial * j % MOD);
        }
        s = (s + factorial) % MOD;
    }
    int m = 0;
    for (int i = 0; i < 100; i++) {
        m = m + i * (i + 1);
    }
    finish = clock();
    cout << s << endl << m << endl;
    cout << "time used = " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
    return 0;
}