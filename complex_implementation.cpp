#include <bits/stdc++.h>
using namespace std;

struct Complex {
    double a, b;
    Complex operator +(Complex z) {
        Complex res;
        res.a = a + z.a;
        res.b = b + z.b;
        return res;
    }
    Complex operator -(Complex z) {
        Complex res;
        res.a = a - z.a;
        res.b = b - z.b;
        return res;
    }
    Complex operator *(Complex z) {
        Complex res;
        res.a = (a * z.a) - (b * z.b);
        res.b = (a * z.b) + (b * z.a);
        return res;
    }
    Complex operator /(Complex z) {
        Complex res;
        res.a = ((a * z.a) + (b * z.b)) / ((z.a * z.a) + (z.b * z.b));
        res.b = ((b * z.a) - (a * z.b)) / ((z.a * z.a) + (z.b * z.b)); 
        return res;
    }
};

int main() {
    Complex z1, z2;
    char op;
    cout << "Escreva a parte real e imaginária do primeiro número: \n";
    cin >> z1.a >> z1.b;
    cout << "\nEscreva a parte real e imaginária do segundo número: \n";
    cin >> z2.a >> z2.b;
    cout << "Qual operação você quer? (+, -, * ou /)\n";
    cin >> op;
    Complex res;
    if (op == '+') {
        res = z1 + z2;
        cout << "\n" << res.a << " " << res.b << "\n";
    } else if (op == '-') {
        res = z1 - z2;
        cout << "\n" << res.a << " " << res.b << "\n";
    } else if (op == '*') {
        res = z1 * z2;
        cout << "\n" << res.a << " " << res.b << "\n";
    } else {
        res = z1 / z2;
        cout << "\n" << res.a << " " << res.b << "\n";
    }
}