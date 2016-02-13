//
//  main.cpp
//  0~9全排列
//
//  Created by ChenXin on 16/2/13.
//  Copyright © 2016年 ChenXin. All rights reserved.
//

#include <iostream>
using namespace std;
int n;
int book[10];
int a[10];
int cou = 0;
void dfs(int step) {
    if (step == 10) {
        cou++;
        if (cou == n) {
            for (int i = 0; i <= 9; i++) {
                cout << a[i];
            }
        }
        return;
    }
    
    for (int i = 0; i <= 9; i++) {
        if (book[i] == 0) {
            a[step] = i;
            book[i] = 1;
            dfs(step + 1);
            book[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    return 0;
}
