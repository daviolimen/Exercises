#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, a;
    scanf("%d", &N);
    vector<int> v{0};
    for (int i = 0; i < N; i++) {
        scanf("%d", &a);
        if (a < v.back()) {
            for (int x = v.back() + 1; x <= a + 10; x++) {
                v.push_back(x);
            }
        } else {
            for (int x = a + 1; x <= a + 10; x++) {
                v.push_back(x);
            }
        }
    }
    printf("%d\n", v.size() - 1);
}