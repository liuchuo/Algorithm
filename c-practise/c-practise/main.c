#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Book {
    char num[20];
    char name[20];
    char author[20];
    char publish[20];
    int count;
    int price;
}books[1000];

void register1();
void enter();
void add_or_delete();
void save();
void inquiry();
void show() ;
void display();

int main() {
    display();
    register1();
    int n;
    scanf("%d", &n);
    switch(n) {
        case 1: enter(); break;
        case 2: inquiry(); break;
        case 3: add_or_delete(); break;
        case 4: exit(0); break;
        default: break;
    }
    show();
    scanf("%d", &n);
    return 0;
}




void register1() {
    char m[20]={'s', 's', 's', '\0'};
    char n[20]={'a', 'a', 'a', '\0'};
    char s[20];
    char a[20];
    printf("please enter the name:");
    scanf("%s", s);
    printf("please enter the password:");
    scanf("%s", a);
    if(strcmp(m, s) == 0 && strcmp(n, a) == 0)
        show();
    else
        exit(0);
    
}


void enter() {
    static int i = 0;
    int m = 1;
    while(m == 1) {
        printf("please enter the name of  book:");
        scanf("%s", books[i].name);
        printf("please enter the name of  author:");
        scanf("%s", books[i].author);
        printf("please enter the name of publishing house:");
        scanf("%s", books[i].publish);
        printf("please enter the number of book:");
        scanf("%d", &books[i].count);
        printf("please enter the identifier:");
        scanf("%s", books[i].num);
        printf("please enter the price:");
        scanf("%d", &books[i].price);
        printf("entering is over.");
        i++;
        printf(" If you want to continue please enter1: ");
        scanf("%d", &m);
        if(m == 1)
            printf("continue\n");
        save();
    }
}



void add_or_delete() {
    int i, count, m;
    printf("1.add the book 2.delete the book. please enter the number:");
    scanf("%d", &m);
    if(m == 0) {
        char name[10];
        printf("please enter the name of book:");
        scanf("%s", name);
        for(i=0; i<1000; i++) {
            if(strcmp(books[i].name, name) == 0) {
                printf("please enter the number of book:");
                scanf("%d", &count);
                books[i].count += count;
                printf("\n The number of the book have added.\n");
                break;
            } else {
                printf("\n We do not have this book. \n");
            }
        }
    } else {
        char name[10];
        printf("please enter the name of book:");
        scanf("%s", name);
        for(i = 0;i < 1000; i++) {
            if(strcmp(books[i].name, name) == 0) {
                printf("please enter the number of book:");
                scanf("%d", &count);
                if(count > books[i].count)
                    printf("We do not have enough book.\n");
                else
                    books[i].count = books[i].count - count;
            } else {
                printf("We do not have the book.\n");
                break;
            }
        }
    }
}


void save() {
    int i = 0;
    FILE *fp;
    fp = fopen("/Users/ChenXin/Downloads/book.txt", "wr");
    while(books[i].count > 0) {
        fprintf(fp, "name:%s author:%s publish:%s count:%d identifer:%s price:%d\n", books[i].name, books[i].author, books[i].publish, books[i].count, books[i].num, books[i].price);
        i++;
    }
    fclose(fp);
}

void display() {
    FILE *fp = fopen("/Users/ChenXin/Downloads/book.txt", "r");
    char s[10];
    while(fgets(s,sizeof(s), fp) != NULL)
        printf("%s", s);
    fclose(fp);
}

void inquiry() {
    FILE *fp;
    int i, flag=0;
    int a;
    char x[32];
    char y[32];
    if((fp = fopen("/Users/ChenXin/Downloads/book.txt", "r")) == NULL) {
        printf("we can not open the file!\n");
        return ;
    }
    printf("please the way which we inquiry: 1.name 2.identifier\n");
    scanf("%d", &a);
    switch(a) {
        case 1:
            printf("please enter the name of book:\n");
            scanf("%s",x);
            for(i=0; i<1000; i++) {
                if (strcmp(books[i].name,x) == 0){
                    printf("name：%s author：%s ：publish %s ：count %d ：num %s  price：%d\n",books[i].name,books[i].author,books[i].publish,books[i].count,books[i].num,books[i].price);
                    flag=1;
                }
            }
            if(flag==0)
                printf("we do not have the book\n");
            break;
        case 2:
            printf("please enter the identifier:\n");
            scanf("%s",y);
            for(i=0; i<1000; i++) {
                if (strcmp(books[i].num,y) == 0) {
                    printf("name:%s author:%s publish:%s count:%d num:%s  price:%d\n",books[i].name,books[i].author,books[i].publish,books[i].count,books[i].num,books[i].price);
                    flag=1;
                }
            }
            if(flag==0)
                printf("We do not have the book.\n");
            break;
        default:
            break;
    }
    fclose(fp);
}


void show() {
    printf("\n      *                         1  enter                        *");
    printf("\n      *                         2  inquiry                      *");
    printf("\n      *                         3  add_or_delete                *");
    printf("\n      *                         4  exit                         *");
    printf("\n please the function:");
}
