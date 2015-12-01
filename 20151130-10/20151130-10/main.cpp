//5.1.5模板
#include <iostream>
using namespace std;

template <typename T>
struct Point {
    T x, y;
    Point(T x = 0, T y = 0) : x(x),y(y) {}
};

// Point operator + (const Point &A, const Point &B) {
//     return Point(A.x + B.x, A.y + B.y);
// }

// ostream &operator << (ostream &out, const Point &p) {
//     out << "(" << p.x << "," << p.y << ")";
//     return out;
// }

template <typename T>
Point<T> operator + (const Point<T> &A, const Point<T> &B) {
    return Point<T>(A.x + B.x, A.y + B.y);
}

template <typename T>
ostream &operator << (ostream &out, const Point<T> &p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

template <typename T>
T sum(T *begin, T *end) {
    T *p = begin;
    T sum = 0;
    for (T *p = begin; p != end; p++) {
        sum = sum + *p;
    }
    return sum;
}

int main() {
    double a[] = {1.1, 2.2, 3.3, 4.4};
    cout << sum(a, a+4) << endl;
    Point<int> e(1, 2), b(3, 4);
    Point<double> c(1.1, 2.2), d(3.3, 4.4);
    cout << e + b << " " << c + d << endl;
    return 0;
}