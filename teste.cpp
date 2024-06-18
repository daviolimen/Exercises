#include <bits/stdc++.h>
using namespace std;

int counter, pts[6];

void search(int n) {
    if (n == 6) {
        if (((pts[0] == pts[1]) && (pts[1] == pts[2])) || ((pts[0] == pts[4]) && (pts[4] == pts[5])) || ((pts[1] == pts[3]) && (pts[3] == pts[5])) || ((pts[2] == pts[3]) && (pts[3] == pts[4]))) return;
        counter++;
        return;
    }

    for (int i = 1; i <= 3; i++) {
        pts[n] = i;
        search(n + 1);
    }
}

int main() {
    search(0);
    cout << counter << "\n";
}