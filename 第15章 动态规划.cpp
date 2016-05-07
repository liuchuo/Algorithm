第15章 动态规划
15.1 钢条切割
//深度优先的递归-自顶向下递归实现
#include <iostream>
using namespace std;
int func(int *p, int n) {
    if(n == 0)
        return 0;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(p[i] + func(p, n - i) > ans) {
            ans = p[i] + func(p, n - i);
        }
    }
    return ans;
}
int main() {
    int p[40] = {0, 1, 5, 8, 9};
    int ans = func(p, 19);
    cout << ans << endl;
    return 0;
}

//自顶向下递归实现-加入备忘机制
#include <iostream>
#include <memory.h>
using namespace std;
int func(int *p, int n, int *r) {
    if(r[n] >= 0)
        return r[n];
    int ans;
    if(n == 0)
        ans = 0;
    else
        ans = -1;
    for(int i = 1; i <= n; i++) {
        if(p[i] + func(p, n - i, r) > ans)
            ans = p[i] + func(p, n - i, r);
    }
    r[n] = ans;
    return ans;
}

int main() {
    int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int *r = new int [11];
    memset(r, -1, sizeof(int) * 11);
    cout << func(p, 10, r);
    return 0;
}



//自底向上的递推实现，并能计算出解
#include <iostream>
using namespace std;
int main() {
    int p[11] = {0, 1, 5, 8, 9, 10};
    int r[11], s[11];
    int n = 10;
    r[0] = 0;
    for(int i = 1; i <= n; i++) {
        int temp = 0;
        for(int j = 1; j <= i; j++) {
            if(p[j] + r[i - j] > temp) {
                temp = p[j] + r[i - j];
                s[i] = j;
            }
        }
        r[i] = temp;
    }
    cout << r[10];
    
    while(n > 0) {
        cout << s[n] << " ";
        n = n - s[n];
    }
    return 0;
}


