#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    queue<char> q;
    for (int i = 0; i < 16; i++) {
        q.push(65+i);
    }
    while (q.size() > 1) {
        scanf("%d%d", &m, &n);
        if (m > n) {
            q.push(q.front());
            q.pop();
            q.pop();
        } else {
            q.pop();
            q.push(q.front());
            q.pop();
        }
    }
    printf("%c\n", q.front());
}