#include <iostream>
using namespace std;
int a[500][500];
int book[500][500];
int n, m;
int min1 = 999999;
char s[2500];
char t[2500];
void dfs(int x, int y, int step) {
    int next[4][2] = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };
    int tx, ty;
    if (x == n && y == m) {
        if (step < min1) {
            min1 = step;
            s[step] = t[step];
        }
        return;
    }
    
    for (int k = 0; k <= 3; k++) {
        tx = x + next[k][0];
        ty = y + next[k][1];
        
        if (tx < 1 || ty < 1 || tx > m || ty > n)
            continue;
        if (a[tx][ty] == 0 && book[tx][ty] == 0) {
            book[tx][ty] = 1;
            if (k == 0) t[step] = 'R';
            if (k == 1) t[step] = 'D';
            if (k == 2) t[step] = 'L';
            if (k == 3) t[step] = 'U';
            dfs(tx, ty, step + 1);
            book[tx][ty] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    book[1][1] = 1;
    dfs(1, 1, 1);
    cout << min1 << endl;
    for (int i = 1; i <= min1; i++) {
        cout << s[i];
    }
    
    return 0;
}