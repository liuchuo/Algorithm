//#include <iostream>
//#include <cmath>
//#include <string>
//using namespace std;
//int main() {
//    string s;
//    cin >> s;
//    int len = s.length();
//    int b[8];
//    for (int k = len - 1; k >= 0; k--) {
//        if (s[k] >= '0' && s[k] <= '9')
//            b[k] = s[k] - '0';
//        else
//            b[k] = s[k] - 'A' + 10;
//    }
//    long long result = 0;
//    for (int j = 0; j <= len - 1; j++) {
//        b[j] = b[j] * pow(16, len - j - 1);
//        result = result + b[j];
//    }
//    cout << result;
//    return 0;
//}

#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    while (cin >> s) {
        int len = s.length();
        long long sum = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] >= 'A' && s[i] <= 'F') {
                sum = sum * 16 + s[i] - 'A' + 10;
            }
            else {
                sum = sum * 16 + s[i] - '0';
            }
        }
        cout << sum;
    }
    return 0;
}