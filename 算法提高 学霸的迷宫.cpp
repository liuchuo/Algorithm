问题描述
　　学霸抢走了大家的作业，班长为了帮同学们找回作业，决定去找学霸决斗。但学霸为了不要别人打扰，住在一个城堡里，城堡外面是一个二维的格子迷宫，要进城堡必须得先通过迷宫。因为班长还有妹子要陪，磨刀不误砍柴功，他为了节约时间，从线人那里搞到了迷宫的地图，准备提前计算最短的路线。可是他现在正向妹子解释这件事情，于是就委托你帮他找一条最短的路线。
输入格式
　　第一行两个整数n， m，为迷宫的长宽。
　　接下来n行，每行m个数，数之间没有间隔，为0或1中的一个。0表示这个格子可以通过，1表示不可以。假设你现在已经在迷宫坐标(1,1)的地方，即左上角，迷宫的出口在(n,m)。每次移动时只能向上下左右4个方向移动到另外一个可以通过的格子里，每次移动算一步。数据保证(1,1)，(n,m)可以通过。
输出格式
　　第一行一个数为需要的最少步数K。
　　第二行K个字符，每个字符∈{U,D,L,R},分别表示上下左右。如果有多条长度相同的最短路径，选择在此表示方法下字典序最小的一个。
样例输入
Input Sample 1:
3 3
001
100
110

Input Sample 2:
3 3
000
000
000
样例输出
Output Sample 1:
4
RDRD

Output Sample 2:
4
DDRR
数据规模和约定
　　有20%的数据满足：1<=n,m<=10
　　有50%的数据满足：1<=n,m<=50
　　有100%的数据满足：1<=n,m<=500。

用广度优先搜索解决。bfs。100分。
#include <iostream>
using namespace std;
struct note {
    int x;
    int y;
    int f;
    int s;
    char dir;
};

int main() {
    char a[501][501];
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
        getchar();
    }
    int head = 1;
    int tail = 1;
    int book[501][501] = {0};
    book[1][1] = 1;
    
    int next[4][2] = {
        {1, 0},
        {0, -1},
        {0, 1},
        {-1, 0}
    };
    int tx = 1;
    int ty = 1;
    
    struct note que[250001];
    que[tail].x = 1;
    que[tail].y = 1;
    que[tail].f = 0;
    que[tail].s = 0;
    tail++;
    int flag = 0;
    while (head < tail) {
        for (int k = 0; k <= 3; k++) {
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];
            
            if (tx < 1 || tx > n || ty < 1 || ty > m)
                continue;
            if (a[tx][ty] == '0' && book[tx][ty] == 0) {
                book[tx][ty] = 1;
                que[tail].x = tx;
                que[tail].y = ty;
                que[tail].f = head;
                que[tail].s = que[head].s + 1;
                if (k == 0) que[tail].dir = 'D';
                else if (k == 1) que[tail].dir = 'L';
                else if (k == 2) que[tail].dir = 'R';
                else if (k == 3) que[tail].dir = 'U';
                tail++;
            }
            if (tx == n && ty == m) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
        head++;
    }
    cout << que[tail - 1].s << endl;
    char t[250001];
    int temp = tail - 1;
    for (int i = que[tail - 1].s; i >= 1; i--) {
        t[i] = que[temp].dir;
        temp = que[temp].f;
    }
    for (int i = 1; i <= que[tail - 1].s; i++) {
        cout << t[i];
    }
    return 0;
}

ps:

如果用深度优先搜索dfs，会超时。30分。
#include <iostream>
using namespace std;
char a[501][501];
int book[501][501];
int n, m;
int min1 = 999999;
char s[250001];
char t[250001];
void dfs(int x, int y, int step) {
    int next[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    int tx, ty;
    if (x == n && y == m) {
        if (step < min1) {
            min1 = step;
            for (int i = 1; i <= min1; i++)
                s[i] = t[i];
        }
        return;
    }
    
    for (int k = 0; k <= 3; k++) {
        tx = x + next[k][0];
        ty = y + next[k][1];
        
        if (tx < 1 || ty < 1 || tx > n || ty > m)
            continue;
        if (a[tx][ty] == '0' && book[tx][ty] == 0) {
            book[tx][ty] = 1;
            if (k == 0) t[step] = 'D';
            if (k == 1) t[step] = 'L';
            if (k == 2) t[step] = 'R';
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
        getchar();
    }
    book[1][1] = 1;
    dfs(1, 1, 1);
    cout << min1 - 1 << endl;
    for (int i = 1; i < min1; i++) {
        cout << s[i];
    }
    
    return 0;
}