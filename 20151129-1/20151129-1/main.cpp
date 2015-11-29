////基础练习 报时助手
//问题描述
//　　给定当前的时间，请用英文的读法将它读出来。
//　　时间用时h和分m表示，在英文的读法中，读一个时间的方法是：
//　　如果m为0，则将时读出来，然后加上“o'clock”，如3:00读作“three o'clock”。
//　　如果m不为0，则将时读出来，然后将分读出来，如5:30读作“five thirty”。
//　　时和分的读法使用的是英文数字的读法，其中0~20读作：
//　　0:zero, 1: one, 2:two, 3:three, 4:four, 5:five, 6:six, 7:seven,
//8:eight, 9:nine, 10:ten, 11:eleven, 12:twelve, 13:thirteen, 14:fourteen,
//15:fifteen, 16:sixteen, 17:seventeen, 18:eighteen, 19:nineteen, 20:twenty。
//　　30读作thirty，40读作forty，50读作fifty。
//　　对于大于20小于60的数字，首先读整十的数，然后再加上个位数。如31首先读30再加1的读法，
//读作“thirty one”。
//　　按上面的规则21:54读作“twenty one fifty four”，9:07读作“nine seven”，0:15读作
//“zero fifteen”。
//输入格式
//　　输入包含两个非负整数h和m，表示时间的时和分。非零的数字前没有前导0。h小于24，m小于60。
//输出格式
//　　输出时间时刻的英文。
//样例输入
//0 15
//样例输出
//zero fifteen

#include <iostream>
using namespace std;

int main() {
    int h, m;
    cin >> h >> m;
    switch(h) {
        case 0: cout << "zero"; break;
        case 1: cout << "one"; break;
        case 2: cout << "two"; break;
        case 3: cout << "three"; break;
        case 4: cout << "four"; break;
        case 5: cout << "five"; break;
        case 6: cout << "six"; break;
        case 7: cout << "seven"; break;
        case 8: cout << "eight"; break;
        case 9: cout << "nine"; break;
        case 10: cout << "ten"; break;
        case 11: cout << "eleven"; break;
        case 12: cout << "twelve"; break;
        case 13: cout << "thirteen"; break;
        case 14: cout << "fourteen"; break;
        case 15: cout << "fifteen"; break;
        case 16: cout << "sixteen"; break;
        case 17: cout << "seventeen"; break;
        case 18: cout << "eighteen"; break;
        case 19: cout << "nineteen"; break;
        case 20: cout << "twenty"; break;
        case 21: cout << "twenty one"; break;
        case 22: cout << "twenty two"; break;
        case 23: cout << "twenty three";break;
    }
    cout << " ";
    if (m == 0)
        cout << "o'clock";
    int t = m % 10;
    m = m / 10;
    switch(m) {
        case 2: cout << "twenty "; break;
        case 3: cout << "thirty "; break;
        case 4: cout << "forty "; break;
        case 5: cout << "fifty "; break;
        default: break;
    }
    if (m == 0 && t != 0) {
        switch(t) {
            case 1: cout << "one"; break;
            case 2: cout << "two"; break;
            case 3: cout << "three"; break;
            case 4: cout << "four"; break;
            case 5: cout << "five"; break;
            case 6: cout << "six"; break;
            case 7: cout << "seven"; break;
            case 8: cout << "eight"; break;
            case 9: cout << "nine"; break;
        }
    }
    if (m == 1) {
        switch(t) {
            case 0: cout << "ten"; break;
            case 1: cout << "eleven"; break;
            case 2: cout << "twelve"; break;
            case 3: cout << "thirteen"; break;
            case 4: cout << "fourteen"; break;
            case 5: cout << "fifteen"; break;
            case 6: cout << "sixteen"; break;
            case 7: cout << "seventeen"; break;
            case 8: cout << "eighteen"; break;
            case 9: cout << "nineteen"; break;
        }
    }
    if (m != 0 && m != 1 && t!= 0) {
        switch(t) {
            case 1: cout << "one"; break;
            case 2: cout << "two"; break;
            case 3: cout << "three"; break;
            case 4: cout << "four"; break;
            case 5: cout << "five"; break;
            case 6: cout << "six"; break;
            case 7: cout << "seven"; break;
            case 8: cout << "eight"; break;
            case 9: cout << "nine"; break;
        }
    }
    return 0;
}
