//sstream
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string a;
    while (getline(cin, a)) {
        int sum = 0;
        int x;
        stringstream ss(a);
        while (ss >> x)
            sum = sum + x;
        cout << sum << endl;
    }
    return 0;
}
