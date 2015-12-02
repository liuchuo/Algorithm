////映射map
//map就是从键（key）到值（value）的映射。
//例如可以用一个map<string, int> month_name 来表示“月份名字到月份编号”的映射
//然后用month_name["July"] = 7 这样的方式来赋值
//例题：反片语
//输入一些单词，找出所有满足如下条件的单词：该单词不能通过字母重排，得到输入文本中的另外一个单词。
//在判断是否满足条件时，字母不分大小写，但在输入时应保留输入中的大小写，按字典序进行排列（所有大写字母在小写字母的前面）
//样例输入：
//ladder came tape soon leader acme RIDE lone Dreis peat
//ScAlE orb eye Rides dealer NotE derail LaCeS drIed
//noel dire Disk mace Rob dries
//样例输出：
//Disk
//NotE
//derail
//drIed
//eye
//ladder
//soon

#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

map<string, int> mapp;
vector<string> words;

//将单词s标准化
string standard(const string &s) {
    string t = s;
    for (int i = 0; i < t.length(); i++) {
        t[i] = tolower(t[i]);
    }
    sort(t.begin(), t.end());
    return t;
}

int main() {
    string s;
    while (cin >> s) {
        if (s[0] == '#')
            break;
        words.push_back(s);
        string r = standard(s);
        if (!mapp.count(r))
            mapp[r] = 0;
        mapp[r]++;
    }
    vector<string> ans;
    for (int i = 0; i < words.size(); i++) {
        if (mapp[standard(words[i])] == 1)
            ans.push_back(words[i]);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
