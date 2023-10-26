#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int lia, car;
    if (a == b) {
        lia = (a + b) * 2;
    } else if (abs(a - b) == 1) {
        lia = (a + b) * 3;
    } else {
        lia = a + b;
    }
    if (c == d) {
        car = (c + d) * 2;
    } else if (abs(c - d) == 1) {
        car = (c + d) * 3;
    } else {
        car = c + d;
    }
    if (lia > car) {
        cout << "Lia\n";
    } else if (car > lia) {
        cout << "Car\n";
    } else {
        cout << "empate\n";
    }
}