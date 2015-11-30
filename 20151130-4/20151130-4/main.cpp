//蛇形填数
#include <iostream>
#include <string.h>
using namespace std;
int a[20][20];

int main() {
    int n, x, y, tot = 0;
    cin >> n;
    memset(a, 0, sizeof(a));
    tot = a[x = 0][y = n - 1] = 1;
    while (tot < n * n) {
        while (x + 1 < n && !a[x + 1][y]) a[++x][y] = ++tot;
        while (y - 1 >= 0 && !a[x][y - 1]) a[x][--y] = ++tot;
        while (x - 1 >= 0 && !a[x - 1][y]) a[--x][y] = ++tot;
        while (y + 1 < n && !a[x][y + 1]) a[x][++y] = ++tot;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", a[i][j]);
        }
        cout << endl;
    }
    return 0;
}
