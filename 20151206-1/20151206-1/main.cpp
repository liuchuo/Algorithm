//xcpcpc
#include <iostream>
#include <string>
using namespace std;

bool isleapyear(int year) {
    if ((year % 4 == 0 && year != 100) || year % 400 == 0)
        return true;
    else
        return false;
}

int main() {
    cout << "请小票票输入今天的年月日~" << endl;
    cout << "如 “2015.07.01” :";
    string a;
    cin >> a;
    int year, month, day;
    year = (a[3] - '0') + (a[2] - '0') * 10
            + (a[1] - '0') * 100 + (a[0] - '0') * 1000;
    month = (a[6] - '0') + (a[5] - '0') * 10;
    day = (a[9] - '0') + (a[8] - '0') * 10;
    int leapyearcount = 0;
    for (int i = 2015; i < year; i++) {
        if (isleapyear(i))
            leapyearcount++;
    }
    int result = 0;
    if (year == 2015) {
        switch (month) {
            case 7 : result = 0; break;
            case 8 : result = 31; break;
            case 9 : result = 62; break;
            case 10 : result = 92; break;
            case 11 : result = 123; break;
            case 12 : result = 153; break;
            default : cout << "error~~" << endl;
                return 0;
        }
        result = result + day;
    }
    if (year < 2015) {
        cout << "error~~~" << endl;
        return 0;
    }
    if (year > 2015) {
        result = 184 + (year - 1 - 2015) * 365 + leapyearcount;
        switch (month) {
            case 1: result += 0; break;
            case 2: result += 31; break;
            case 3: result += 59; break;
            case 4: result += 90; break;
            case 5: result += 120; break;
            case 6: result += 151; break;
            case 7: result += 181; break;
            case 8: result += 212; break;
            case 9: result += 243; break;
            case 10: result += 273; break;
            case 11: result += 304; break;
            case 12: result += 334; break;
        }
        result += day;
        if (isleapyear(year) && month >= 3)
            result += 1;
        }
    cout << "亲爱的小票票，我们从2015.07.01至今，已经在一起" << result << "天了呢~~嘤嘤嘤好开心~~" << endl;
    return 0;
}