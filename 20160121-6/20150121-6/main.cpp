//算法提高 新建Microsoft Word文档
/*时间限制：1.0s   内存限制：256.0MB
提交此题
问题描述
　　L正在出题，新建了一个word文档，想不好取什么名字，身旁一人惊问：“你出的题目叫《新建Microsoft Word文档》吗？”，L大喜，一拍桌子，说：“好，就叫这个名字了。”
　　仔细观察，当你新建一个word文档时，会得到一个名为“新建 Microsoft Word 文档.doc”的文件，再新建一个，则名为“新建 Microsoft Word 文档(2).doc”，再新建，便是“新建 Microsoft Word 文档(3).doc”。不断新建，编号不断递增。倘若你现在新建了三个文档，然后删除了“新建 Microsoft Word 文档(2).doc”，再新建就又会得到一个“新建 Microsoft Word 文档(2).doc”。

　　严格说，Windows在每次新建文档时，都会选取一个与已有文件编号不重复的最小正整数作为新文档的编号。

　　请编程模拟以上过程，支持以下两种操作
　　New：新建一个word文档，反馈新建的文档的编号
　　Delete id：删除一个编号为id的word文档，反馈删除是否成功
　　初始时一个文件都没有，“新建 Microsoft Word 文档.doc”的编号算作1。
输入格式
　　第一行一个正整数n表示操作次数，接下来n行，每行表示一个操作。若该行为”New”，则表示新建，为”Delete id”则表示要删除编号为id的文档，其中id为一个正整数。操作按输入顺序依次进行。
输出格式
　　对于输入的每一行，输出其反馈结果。对于新建操作，输出新建的文档的编号；对于删除操作，反馈删除是否成功：如果删除的文件存在，则删除成功，输出”Successful”，否则输出”Failed”。
样例输入
12
New
New
New
Delete 2
New
Delete 4
Delete 3
Delete 1
New
New
New
Delete 4
样例输出
1
2
3
Successful
2
Failed
Successful
Successful
1
3
4
Successful
数据规模和约定
　　操作次数（即输入的行数）不超过1481
　　删除编号的数值不超过2012
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int cmp(int a, int b) {
    return a < b;
}

int delnum(string s) {
    int len;
    len = s.length();
    if(len == 11) {
        return (s[7] - '0') * 1000 + (s[8] -'0') * 100 + (s[9] - '0') * 10 + (s[10] - '0');
    } else if(len == 10) {
        return (s[7] - '0') * 100 + (s[8] -'0') * 10 + (s[9] - '0');
    } else if(len == 9) {
        return (s[7] - '0') * 10 + (s[8] -'0');
    } else {
        return s[7] - '0';
    }
}

int main() {
    int n;
    cin >> n;
    int a[1500];
    for (int i = 0; i < 1500; i++)
        a[i] = 2013;
    int b[1500] = {0};
    int count = 1;
    int k = 0;
    cin.get();
    for (int i = 0; i < n; i++) {
        
        string s;
        getline(cin, s);
        int flag = 0;
        sort(a, a+1500, cmp);
        if (s[0] == 'N') {
            if (a[0] == 2013) {
                cout << count << endl;
                b[k++] = count;
                count++;
            } else {
                cout << a[0] << endl;
                b[k++] = a[0];
                a[0] = 2013;
            }
        } else {
            for (int l = 0; l <= k; l++) {
                if(b[l] == delnum(s)) {
                    for(int j = 0; j < 1500; j++) {
                        if (a[j] == 2013) {
                            a[j] = delnum(s);
                            cout << "Successful" << endl;
                            b[l] = 0;
                            break;
                        }
                    }
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                cout << "Failed" << endl;
            }
        }
    }
    return 0;
}
