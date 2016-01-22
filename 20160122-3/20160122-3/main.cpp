/*算法提高 上帝造题五分钟
时间限制：1.0s   内存限制：256.0MB
提交此题
问题描述
　　第一分钟，上帝说：要有题。于是就有了L，Y，M，C
　　第二分钟，LYC说：要有向量。于是就有了长度为n写满随机整数的向量
　　第三分钟，YUHCH说：要有查询。于是就有了Q个查询，查询向量的一段区间内元素的最小值
　　第四分钟，MZC说：要有限。于是就有了数据范围
　　第五分钟，CS说：要有做题的。说完众神一哄而散，留你来收拾此题
输入格式
　　第一行两个正整数n和Q，表示向量长度和查询个数
　　接下来一行n个整数，依次对应向量中元素：a[0]，a[1]，…，a[n-1]
　　接下来Q行，每行两个正整数lo，hi，表示查询区间[lo, hi]中的最小值，即min(a[lo],a[lo+1],…,a[hi])。
输出格式
　　共Q行，依次对应每个查询的结果，即向量在对应查询区间中的最小值。
样例输入
7 4
1 -1 -4 8 1 2 -7
0 0
1 3
4 5
0 6
样例输出
1
-4
1
-7
样例说明
　　第一个查询[0,0]表示求min{a[0]}=min{1}=1
　　第二个查询[1,3]表示求min{a[1],a[2],a[3]}=min{-1,-4,8}=-4
　　第三个查询[4,5]表示求min{a[4],a[5]}=min{1,2}=1
　　第四个查询[0,6]表示查询整个向量，求min{a[0..6]}=min{1,-1,-4,8,1,2,-7}=-7
数据规模和约定
　　1<=n<=1984，1<=Q<=1988，向量中随机整数的绝对值不超过1,000
*/
#include <iostream>
#include <algorithm>
int cmp(int a, int b) {return a < b;}

using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    int *a = new int [n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < q; i++) {
        int low, high;
        cin >> low >> high;
        int *b = new int [high - low + 1];
        int temp = low;
        for (int j = 0; j < high - low + 1; j++)
            b[j] = a[temp++];
        sort(b, b + high - low + 1, cmp);
        cout << b[0] << endl;
        delete [] b;
    }
    delete [] a;
    return 0;
}