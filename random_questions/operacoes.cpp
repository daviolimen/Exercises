#include <iostream>
using namespace std;

int main() {
    char op;
    double x, y;
    cin >> op >> x >> y;
    if (op == 'M') {
        printf("%.2lf\n", x * y);
    } else {
        printf("%.2lf\n", x / y);
    }
    return 0;
}