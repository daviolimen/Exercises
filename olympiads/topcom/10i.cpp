#include <bits/stdc++.h>
using namespace std;

int eval(int b, const vector<int> &nums, const vector<bool> &ops) {
    int res = nums[0];
    for (int i = 0; i < ops.size(); i++) {
        
    }
}

int main() {
    while (true) {
        string tudo; cin >> tudo;
        if (tudo == "=") break;
        int n = tudo.size();
        vector<bool> ops[2];
        vector<int> nums[2];
        bool flag = 0;
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (tudo[i] == '=') {
                nums[flag].push_back(num);
                num = 0;
                flag = 1;
            } else if (tudo[i] == '+') {
                ops[flag].push_back(0);
                nums[flag].push_back(num);
                num = 0;
            } else if (tudo[i] == '*') {
                ops[flag].push_back(1);
                nums[flag].push_back(num);
                num = 0;
            } else {
                num *= 10;
                num += (tudo[i] - '0');
            }
        }
        nums[flag].push_back(num);
        num = 0;
        

    }
}