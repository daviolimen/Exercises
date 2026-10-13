#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    scanf("%d%d", &a, &b);
    unordered_set<int> alice, beatriz;
    for (int i = 0; i < a; i++) {
        scanf("%d", &c);
        alice.insert(c);
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < b; i++) {
        scanf("%d", &c);
        beatriz.insert(c);
    }
    for (auto x : alice) {
        if (beatriz.find(x) == beatriz.end()) {
            ans1++;
        }
    }
    for (auto x : beatriz) {
        if (alice.find(x) == alice.end()) {
            ans2++;
        }
    }
    printf("%d", -max(-ans1, -ans2));
}