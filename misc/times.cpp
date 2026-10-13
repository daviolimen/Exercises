#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    pair<int, string> arr[n];
    for (int i = 0; i < n; i++) {
        int hab;
        string jog;
        cin >> jog >> hab;
        arr[i].first = hab;
        arr[i].second = jog;
    }
    sort(arr, arr+n);
    vector<vector<string>> times;
    for (int i = 0; i < t; i++) {
        vector<string> time;
        times.push_back(time);
    }
    int itr = n - 1;
    while (itr >= 0) {
        for (int i = 0; i < t; i++) {
            if (itr < 0) {
                break;
            }
            times[i].push_back(arr[itr].second);
            itr--;
        }
    }
    for (int i = 0; i < t; i++) {
        cout << "Time " << i + 1 << "\n";
        for (int j = 0; j < times[i].size(); j++) {
            cout << times[i][j] << "\n";
        }
    }
}