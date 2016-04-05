#include <iostream>
#include <set>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    set<char> t1, t2;
    for(int i = 0; i <= s1.length(); i++) {
        t1.insert(s1[i]);
    }
    for(int i = 0; i <= s2.length(); i++) {
        t2.insert(s2[i]);
    }
    
    set<char>::iterator it1 = t1.begin();
    set<char>::iterator it2 = t2.begin();
    while(it1 != t1.end() && it2 != t2.end()) {
        if(*it1 == *it2) {
            it2++;
        }
        it1++;
    }
    if(it2 != t2.end()) {
        cout << "false";
    } else {
        cout << "true";
    }
    return 0;
}

#include <iostream>
using namespace std;
int book[26];
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.length(); i++) {
        book[s1[i] - 'A'] = 1;
    }
    for(int i = 0; i < s2.length(); i++) {
        if(book[s2[i] - 'A'] == 0) {
            cout << "false";
            return 0;
        }
    }
    cout << "true";
    return 0;
}


#include <iostream>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int a = 0;
    for(int i = 0; i < s1.length(); i++) {
        
    }
    
    return 0;
}