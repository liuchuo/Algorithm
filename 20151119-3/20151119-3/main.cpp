////1025. 反转链表 (25)
//
//时间限制
//300 ms
//内存限制
//65536 kB
//代码长度限制
//8000 B
//判题程序
//Standard
//作者
//CHEN, Yue
//给定一个常数K以及一个单链表L，请编写程序将L中每K个结点反转。
//例如：给定L为1→2→3→4→5→6，K为3，则输出应该为3→2→1→6→5→4；
//如果K为4，则输出应该为4→3→2→1→5→6，即最后不到K个元素不反转。
//
//输入格式：
//
//每个输入包含1个测试用例。每个测试用例第1行给出第1个结点的地址、
//结点总个数正整数N(<= 105)、以及正整数K(<=N)，
//即要求反转的子链结点的个数。结点的地址是5位非负整数，NULL地址用-1表示。
//
//接下来有N行，每行格式为：
//
//Address Data Next
//
//其中Address是结点地址，Data是该结点保存的整数数据，Next是下一结点的地址。
//
//输出格式：
//
//对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。
//
//输入样例：
//00100 6 4
//00000 4 99999
//00100 1 12309
//68237 6 -1
//33218 3 00000
//99999 5 68237
//12309 2 33218
//输出样例：
//00000 4 33218
//33218 3 12309
//12309 2 00100
//00100 1 99999
//99999 5 68237
//68237 6 -1

#include <iostream>
#include <string>
using namespace std;
struct node {
    string no;
    int data;
    string next;
};

void sort1(node a[], int n, string firstnode);
void Reverse(node a[], int l, int r);
void print(node a[], int k, int t, int n);

int main() {
    string firstnode;
    cin >> firstnode;
    int n;
    cin >> n;
    int k;
    cin >> k;
    node *a = new node [n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].no >> a[i].data >> a[i].next;
    }
    sort1(a, n, firstnode);
    int t = n / k;
    for (int i = 0; i <= k * (t - 1); i += k) {
        Reverse(a, i, i + k - 1);
    }
    for (int i = 0; i <= k * (t - 1); i += k) {
        a[i + k - 1].next = a[i + k].no;
    }
    print(a, k, t, n);
    delete [] a;
    return 0;
}

void sort1(node a[], int n, string firstnode) {
    node temp;
    for (int i = 0; i < n; i++) {
        if (a[i].no == firstnode) {
            temp = a[i];
            a[i] = a[0];
            a[0] = temp;
        }
        if (a[i].next == "-1") {
            temp = a[i];
            a[i] = a[n - 1];
            a[n - 1] = temp;
        }
    }
    for (int i = 0; i <= n - 3; i++) {
        for (int j = i + 1; j <= n - 2; j++) {
            if (a[i].next == a[j].no) {
                temp = a[j];
                a[j] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}

void Reverse(node a[], int l, int r) {
    node temp;
    int count = r - l + 1;
    for (int i = r; i > (r + l) / 2; i--) {
        temp = a[i];
        a[i] = a[count - i - 1];
        a[count - i - 1] = temp;
        if (i != r) {
            a[i].next = a[i + 1].no;
        }
    }
    for (int i = l; i <= (r + l) / 2; i++) {
        a[i].next = a[i + 1].no;
    }
}

void print(node a[], int k, int t, int n) {
    for (int i = 0; i <= k * (t - 1); i += k) {
        for (int j = 0; j < k; j++) {
            cout << a[i + j].no << " " << a[i + j].data
            << " " << a[i + j].next << endl;
        }
    }
    for (int j = t * k; j < n; j++) {
        cout << a[j].no << " " << a[j].data
        << " " << a[j].next << endl;
    }
}