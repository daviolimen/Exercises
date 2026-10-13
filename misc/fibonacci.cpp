#include <bits/stdc++.h>
using namespace std;

pair<int, int> fib(int n, int &calls) {
    if (n == 0) {
        return make_pair(0, 0);
    } else if (n == 1) {
        return make_pair(1, 0);
    } else {
        calls += 2;
        return make_pair((fib(n - 1, calls).first + fib(n - 2, calls).first), calls);
    }
}

int main() {
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        int calls = 0;
        auto ans = fib(x, calls);
        printf("fib(%d) = %d calls = %d\n", x, ans.second, ans.first);
    }
}