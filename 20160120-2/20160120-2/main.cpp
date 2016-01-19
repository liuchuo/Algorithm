
//数字三角形：第二种方法，递推o(n^2)
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    int a[101][101];
    int d[101][101];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        d[n][i] = a[n][i];//边界处理
    for (int i = n - 1; i >= 1; i--)
        for(int j = 1; j <= i; j++)
            d[i][j] = a[i][j] + max(d[i + 1][j], d[i + 1][j + 1]);
    cout << d[1][1];
    return 0;
}
