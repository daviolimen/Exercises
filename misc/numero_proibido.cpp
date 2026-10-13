#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p;
    scanf("%d", &n);
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &p);
        s.insert(p);
    }
    while (scanf("%d", &p) != EOF) {
        if (s.find(p) == s.end()) printf("nao\n");
        else printf("sim\n");
    }
}