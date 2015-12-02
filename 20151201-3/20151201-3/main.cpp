////集合：set
//输入一个文本，找出所有不同的单词，按照字典从小到大的顺序输出，单词不区分大小写
//
//样例输入：
//Adventures in Disneyland
//Two blondes were going to Disneyland when they came to a fork in the road.
//The sign read : "Disneyland left."
//So they went home.
//
//输入时把所有非字母的字符变成空格，然后利用stringstream得到各单词

#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <cctype>
using namespace std;

set<string> dict;
int main() {
    string s, buf;
    while (cin >> s) {
        for (int i = 0; i < s.length(); i++) {
            if(isalpha(s[i]))  //<iostream>
                s[i] = tolower(s[i]); //#include <cctype>
            else
                s[i] = ' ';
        }
        stringstream ss(s);
        while (ss >> buf)
            dict.insert(buf);
    }
    for (set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}
