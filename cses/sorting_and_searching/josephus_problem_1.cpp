#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

struct Node {
    int data, prev, next;
    Node(int a = 0, int b = 0, int c = 0) : data(a), prev(b), next(c) {}
};

int n;
Node arr[MAXN];

void pop(int idx) {
    arr[arr[idx].prev].next = arr[idx].next;
    arr[arr[idx].next].prev = arr[idx].prev;
}

int main() {
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    arr[1] = Node(1, n, 2);
    arr[n] = Node(n, n - 1, 1);
    for (int i = 2; i < n; i++) arr[i] = Node(i, i - 1, i + 1);

    int curr = 2;

    for (int i = 1; i <= n; i++) {
        cout << curr << " \n"[i == n];
        pop(curr);
        curr = arr[curr].next;
        curr = arr[curr].next;
    }
}