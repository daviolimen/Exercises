#include <bits/stdc++.h>
using namespace std;

struct Matrix {
    double a[2][2] = {{0, 0}, {0, 0}};
    Matrix operator *(const Matrix &b) {
        Matrix res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    res.a[i][j] += a[i][k] * b.a[k][j];
                }
            }
        }
        return res;
    }
};

Matrix expo_power(Matrix a, int k) {
    Matrix res;
    res.a[0][0] = 1;
    res.a[1][1] = 1;
    while (k > 0) {
        if (k & 1) res = res * a;
        a = a * a;
        k >>= 1;
    }
    return res;
}

int main() {
    
}