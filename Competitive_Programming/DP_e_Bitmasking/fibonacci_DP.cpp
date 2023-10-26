#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

#define MAXN 100010

int n;
bool mark[MAXN];
ull dp[MAXN];

ull fib(int x) {
    if (x <= 1) return 1;
    if (mark[x]) return dp[x];
    mark[x] = true;
    return dp[x] = fib(x - 1) + fib(x - 2);
}


int main() {
    cin >> n;
    cout << fib(n) << "\n";
}