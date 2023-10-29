#include <bits/stdc++.h>
using namespace std;

int L;
pair<int, int> arr[3];

int main() {
    int totalArea = 0;
    for (int i = 0; i < 3; i++) {
        int x, y; cin >> x >> y;
        arr[i].first = max(x, y), arr[i].second = min(x, y);
        totalArea += arr[i].first * arr[i].second;
    }

    for (int i = 1; i <= 100; i++) {
        if (i * i == totalArea) {
            L = i;
            break;
        }
    }

    if (!L) {
        cout << "-1\n";
        return 0;
    }

    int ctr = 0;

    for (int i = 0; i < 3; i++) {
        if (arr[i].first == L) ctr++;
    }

    if ((ctr == 0) || (ctr == 2)) {
        cout << "-1\n";
        return 0;
    }

    cout << L << "\n";

    if (ctr == 3) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < arr[i].second; j++) {
                for (int k = 0; k < L; k++) cout << (char) ('A' + i);
                cout << "\n";
            }
        }
        return 0;
    }

    int idxOfL;

    for (int i = 0; i < 3; i++) {
        if (arr[i].first == L) {
            idxOfL = i;
            break;
        }
    }

    for (int i = 0; i < arr[idxOfL].second; i++) {
        for (int j = 0; j < L; j++) cout << (char) ('A' + idxOfL);
        cout << "\n";
    }

    int notL[2], curr = 0;

    for (int i = 0; i < 3; i++) {
        if (i != idxOfL) {
            notL[curr] = i;
            curr++;
        }
    }

    for (int i = 0; i < (L - arr[idxOfL].second); i++) {
        if (arr[notL[0]].first + arr[idxOfL].second == L) {
            for (int j = 0; j < arr[notL[0]].second; j++) cout << (char) ('A' + notL[0]);
        } else {
            for (int j = 0; j < arr[notL[0]].first; j++) cout << (char) ('A' + notL[0]);
        }
        if (arr[notL[1]].first + arr[idxOfL].second == L) {
            for (int j = 0; j < arr[notL[1]].second; j++) cout << (char) ('A' + notL[1]);
        } else {
            for (int j = 0; j < arr[notL[1]].first; j++) cout << (char) ('A' + notL[1]);
        }
        cout << "\n";
    }
}