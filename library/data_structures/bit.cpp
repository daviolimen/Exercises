#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int n, bit[MAXN];

void update(int k, int x) {
    for (; k <= n; k += (k & -k)) {
        bit[k] += x;
    }
}

int soma(int k) {
    int s = 0;
    for (; k > 0; k -= (k & -k)) {
        s += bit[k];
    }
    return s;
}

int main() {
    
}