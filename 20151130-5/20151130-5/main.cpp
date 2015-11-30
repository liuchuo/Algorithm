//scanf("%s",s)
#include <iostream>
using namespace std;

int main() {
    char s[20];
    scanf("%s",s);
    cout << s;
    return 0;
}

//sprintf(a, "%d%d%d", b, c, d);
#include <string.h>
int main() {
    char a[100];
    int b = 1, c = 2, d = 3;
    sprintf(a, "%d%d%d", b, c, d);
    cout << a;
    return 0;
}