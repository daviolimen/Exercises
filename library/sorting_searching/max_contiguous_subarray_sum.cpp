#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    scanf("%d", &n);
    int best = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        sum = max(a, sum + a);
        best = max(sum, best);
    }
    cout << best << "\n";
}