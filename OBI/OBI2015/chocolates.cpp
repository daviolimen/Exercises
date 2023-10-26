#include <bits/stdc++.h>
using namespace std;

int n;

int quad(int x, int y) {
    int cmp = n / 2;
    if ((x > cmp) && (y > cmp)) return 1;
    else if ((x <= cmp) && (y > cmp)) return 2;
    else if ((x <= cmp) && (y <= cmp)) return 3;
    else return 4;
}

int main() {
    int x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    bool ans = true;
    if (quad(x1, y1) == quad(x2, y2)) ans = false;

    cout << ((ans) ? "S\n" : "N\n");
}