#include <iostream>
#include <stack>
using namespace std;
const int MAXN = 1000;
int n;
int target[MAXN];

int main() {
    while (cin >> n) {
        stack<int> s;
        int A = 1;
        int B = 1;
        for (int i = 1; i <= n; i++) {
            cin >> target[i];
        }
        int flag = 1;
        while (B <= n) {
            if (A == target[B]) {
                A++;
                B++;
            }
            else if(!s.empty() && s.top() == target[B]) {
                s.pop();
                B++;
            }
            else if(A <= n) {
                s.push(A);
                A++;
            }
            else {
                flag = 0;
                break;
            }
        }
        cout << (flag ? "YES" : "NO");
    }
    return 0;
}