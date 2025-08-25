#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    scanf("%d", &n);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a == 0) {
            v.pop_back();
        } else {
            v.push_back(a);
        }
    }
    int sum = 0;
    for (auto x : v) {
        sum += x;
    }
    printf("%d\n", sum);
}