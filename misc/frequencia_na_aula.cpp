#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, v;
    scanf("%d", &n);
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        s.insert(v);
    }
    printf("%d\n", s.size());
}