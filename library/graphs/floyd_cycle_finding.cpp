#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

#define MAXN 100001

int n, succ[MAXN];

pi floydCycleFinding(int x) {
    int tortoise = succ[x], hare = succ[succ[x]];

    while (tortoise != hare) {
        tortoise = succ[tortoise];
        hare = succ[succ[hare]];
    }

    int hare = x;

    while (tortoise != hare) {
        tortoise = succ[tortoise];
        hare = succ[hare];
    }

    int first = hare;

    int length = 1, tortoise = x, hare = succ[x];

    while (tortoise != hare) {
        hare = succ[hare];
        length++;
    }

    return {first, length};
}