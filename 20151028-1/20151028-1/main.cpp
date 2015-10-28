//看商品猜价格
#include <stdio.h>
int main() {
    int oldprice;
    int price = 0;
    int i = 0;
    printf("设置商品的真实价格为：");
    scanf("%d",&oldprice);
    printf("请输入试猜价格：");
    while(oldprice != price) {
        i++;
        printf("参与者：");
        scanf("%d",&price);
        printf("主持人：");
        if(price > oldprice)
            printf("高了\n");
        else if(price < oldprice)
            printf("低了\n");
        else
            printf("恭喜你答对了~,你一共试猜了%d次\n",i);
    }
    return 0;
}
