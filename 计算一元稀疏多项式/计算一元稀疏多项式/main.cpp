#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <limits.h>
using namespace std;
//  单链表多项式结点的结构体定义
//  m表示多项式每一项的系数，n表示多项式每一项的指数
typedef struct PolynNode {
    double m;
    int n;
    struct PolynNode *next;
}ListNode;

//  vector不定长数组结构体，用来存储系数与指数并排序
typedef struct node {
    double m;
    int n;
}Node;


//  函数声明
void CreatePolyn(ListNode *head);
void PrintPolyn(ListNode *HeadC);
void AddPolyn(ListNode *HeadA, ListNode *HeadB, ListNode *HeadC);
void SubPolyn(ListNode *HeadA, ListNode *HeadB, ListNode *HeadC);
void EntryOperator(char *t);
int cmp1(Node X, Node Y);


//  vector不定长数组的排序函数
int cmp1(Node X, Node Y) {
    return X.n < Y.n;
}


//  输入并建立多项式
void CreatePolyn(ListNode *head) {
    cout << "请分别输入多项式的系数和指数，并以“-99 -99”结尾：";
    //  将多项式的每一项数据存入不定长数组中
    double a;
    int b;
    cin >> a >> b;
    vector<Node> v;
    while(a != -99 || b != -99) {
        Node temp;
        temp.m = a;
        temp.n = b;
        v.push_back(temp);
        cin >> a >> b;
    }
    //  对不定长数组排序
    sort(v.begin(), v.end(), cmp1);
    //  合并输入重复的多项式的项
    for(int i = 1; i < v.size(); i++) {
        if(v[i].n == v[i-1].n) {
            v[i].m = v[i].m + v[i-1].m;
            v[i-1].n = INT_MAX;
        }
    }
    sort(v.begin(), v.end(), cmp1);
    ListNode *p = head;
    //  将不定长数组里的数据存入结点元素，并按升序构建单链表
    for(vector<Node>::iterator it = v.begin(); it != v.end(); it++) {
        if((*it).n == INT_MAX)
            break;
        ListNode *TempNode = (ListNode *)malloc(sizeof(ListNode));
        TempNode->m = (*it).m;
        TempNode->n = (*it).n;
        TempNode->next = NULL;
        p->next = TempNode;
        p = p->next;
    }
}


//  输出多项式，输出形式为整数序列，序列按指数升序序列
void PrintPolyn(ListNode *HeadC) {
    cout << "=====输出运算结果=====" << endl;
    cout << "一元稀疏多项式A与B的运算结果为： " ;
    ListNode *c = HeadC->next;
    //  输出单链表中所有不为0的项
    while(c!= NULL) {
        if(c->m != 0.0) {
            printf("%.2fx^%d", c->m, c->n);
            break;
        }
        c = c->next;
    }
    if(c != NULL)
        c = c->next;
    while(c != NULL) {
        if(c->m == 0.0)
            continue;
        //  如果该结点的系数为非负数，则在前面加上'+'号
        if(c->m > 0.0) {
            cout << "+";
        }
        printf("%.2fx^%d", c->m, c->n);
        c = c->next;
    }
    cout << endl;
}


//  多项式 A 和 B 相加，建立多项式 A + B ，输出相加的多项式
void AddPolyn(ListNode *HeadA, ListNode *HeadB, ListNode *HeadC) {
    ListNode *p = HeadA->next;
    ListNode *q = HeadB->next;
    ListNode *c = HeadC;
    // 当AB链表都不为空的时候，将A链表和B链表相加
    while(p != NULL && q != NULL) {
        ListNode *TempNode = (ListNode *)malloc(sizeof(ListNode));
        if(p->n < q->n) {
            TempNode->m = p->m;
            TempNode->n = p->n;
            TempNode->next = NULL;
            c->next = TempNode;
            c = c->next;
            p = p->next;
        } else if(p->n > q->n) {
            TempNode->m = q->m;
            TempNode->n = q->n;
            TempNode->next = NULL;
            c->next = TempNode;
            c = c->next;
            q = q->next;
        } else {
            TempNode->m = p->m + q->m;
            TempNode->n = q->n;
            TempNode->next = NULL;
            c->next = TempNode;
            c = c->next;
            p = p->next;
            q = q->next;
        }
    }
    //  将A链表剩余部分连接入C链表
    while(p != NULL) {
        ListNode *TempNode = (ListNode *)malloc(sizeof(ListNode));
        TempNode->m = p->m;
        TempNode->n = p->n;
        TempNode->next = NULL;
        c->next = TempNode;
        c = c->next;
        p = p->next;
    }
    //  将B链表剩余部分连接入C链表
    while(q != NULL) {
        ListNode *TempNode = (ListNode *)malloc(sizeof(ListNode));
        TempNode->m = q->m;
        TempNode->n = q->n;
        TempNode->next = NULL;
        c->next = TempNode;
        c = c->next;
        q = q->next;
    }
    
}


//  多项式 A 和 B 相减，建立多项式 A - B，输出相减的多项式
void SubPolyn(ListNode *HeadA, ListNode *HeadB, ListNode *HeadC) {
    ListNode *p = HeadA->next;
    ListNode *q = HeadB->next;
    ListNode *c = HeadC;
    // 当AB链表都不为空的时候，将A链表和B链表相减
    while(p != NULL && q != NULL) {
        ListNode *TempNode = (ListNode *)malloc(sizeof(ListNode));
        if(p->n < q->n) {
            TempNode->m = p->m;
            TempNode->n = p->n;
            TempNode->next = NULL;
            c->next = TempNode;
            c = c->next;
            p = p->next;
        } else if(p->n > q->n) {
            TempNode->m = 0 - q->m;
            TempNode->n = q->n;
            TempNode->next = NULL;
            c->next = TempNode;
            c = c->next;
            q = q->next;
        } else {
            TempNode->m = p->m - q->m;
            TempNode->n = q->n;
            TempNode->next = NULL;
            c->next = TempNode;
            c = c->next;
            p = p->next;
            q = q->next;
        }
    }
    //  将A链表剩余部分连接入C链表
    while(p != NULL) {
        ListNode *TempNode = (ListNode *)malloc(sizeof(ListNode));
        TempNode->m = p->m;
        TempNode->n = p->n;
        TempNode->next = NULL;
        c->next = TempNode;
        c = c->next;
        p = p->next;
    }
    //  将B链表剩余部分连接入C链表
    while(q != NULL) {
        ListNode *TempNode = (ListNode *)malloc(sizeof(ListNode));
        TempNode->m = 0 - q->m;
        TempNode->n = q->n;
        TempNode->next = NULL;
        c->next = TempNode;
        c = c->next;
        q = q->next;
    }
}


//  输入多项式 A 与 B 需要操作的运算符
void EntryOperator(char *ch) {
    cout << "请输入‘+’或者‘-’：";
    cin >> (*ch);
    if((*ch) != '+' && (*ch) != '-') {
        cout << endl << "抱歉，输入有误~~";
        EntryOperator(ch);
    }
    return ;
}


//  主函数
int main(int argc, const char * argv[]) {
    ListNode *HeadA = (ListNode *)malloc(sizeof(ListNode));
    ListNode *HeadB = (ListNode *)malloc(sizeof(ListNode));
    ListNode *HeadC = (ListNode *)malloc(sizeof(ListNode));
    HeadA->next = NULL;
    HeadB->next = NULL;
    HeadC->next = NULL;
    cout << "====创建多项式A====" << endl;
    CreatePolyn(HeadA);
    cout << "====创建多项式A成功！====" << endl;
    
    char ch;
    EntryOperator(&ch);
    
    cout << "====创建多项式B====" << endl;
    CreatePolyn(HeadB);
    cout << "====创建多项式B成功！====" << endl;
    
    if(ch == '+') {
        AddPolyn(HeadA, HeadB, HeadC);
    } else {
        SubPolyn(HeadA, HeadB, HeadC);
    }
    
    PrintPolyn(HeadC);
    return 0;
}
