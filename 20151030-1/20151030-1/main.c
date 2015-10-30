//填数游戏 枚举（穷举）算法思想
//算法描述题
//x     算
//---------
//题题题题题题
#include <stdio.h>
int main() {
    int i1,i2,i3,i4,i5;
    long multi,result;
    for(i1 = 1;i1 <= 9;i1++) {
        for(i2 = 0;i2 <= 9;i2++) {
            for(i3 = 0;i3 <= 9;i3++) {
                for(i4 = 0;i4 <= 9;i4++) {
                    for(i5 = 1;i5 <= 9;i5++) {
                        multi = i1 * 10000 + i2 * 1000 + i3 * 100 + i4 * 10 + i5;
                        result = i5 * 100000 + i5 * 10000 + i5 * 1000 + i5 * 100 + i5 * 10 + i5;
                        if(multi * i1 == result) {
                            printf("%5d%2d%2d%2d%2d\n",i1,i2,i3,i4,i5);
                            printf("X%12d\n",i1);
                            printf("---------------\n");
                            printf("%3d%2d%2d%2d%2d%2d\n",i5,i5,i5,i5,i5,i5);
                        }
                    }
                }
            }
        }
    }
    getchar();
    return 0;
}
