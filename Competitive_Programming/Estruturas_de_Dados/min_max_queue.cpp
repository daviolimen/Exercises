#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

struct MinQueue {
    deque<pi> dq;
    int l, r;

    void init() {
        l = r = 1;
        dq.clear();
    }

    void push(int v) {
        while (!dq.empty() && v < dq.back().first) {
            dq.pop_back();
        }
        dq.emplace_back(v, r);
        r++;
    }

    void pop() {
        if (!dq.empty() && dq.front().second == l) dq.pop_front();
        l++;
    }

    int getmin() {
        return dq.front().first;
    }
};

int main() {

}