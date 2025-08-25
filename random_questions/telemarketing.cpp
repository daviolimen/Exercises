#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010

int nums[MAXN];

int main() {
    int N, L, T;
    scanf("%d%d", &N, &L);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= L; i++) {
        scanf("%d", &T);
        if (pq.size() == N) {
            auto temp = pq.top();
            pq.pop();
            pq.push(make_pair(temp.first + T, temp.second));
            nums[temp.second]++;
        } else {
            pq.push(make_pair(T, i));
            nums[i]++;
        }
    }
    for (int i = 1; i <= N; i++) {
        printf("%d %d\n", i, nums[i]);
    }
}