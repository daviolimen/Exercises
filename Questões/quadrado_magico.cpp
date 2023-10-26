#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[3][3];
    int a;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &a);
            arr[i][j] = a;
        }
    }
    int sum = arr[0][0] + arr[0][1] + arr[0][2];
    int atual = 0;
    for (int i = 1; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            atual += arr[i][j];
        }
        if (atual == sum) {
            atual = 0;
            continue;
        }
        printf("NAO\n");
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            atual += arr[j][i];
        }
        if (atual == sum) {
            atual = 0;
            continue;
        }
        printf("NAO\n");
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        atual += arr[i][i];
    }
    if (atual == sum) {
        atual = 0;
    } else {
        printf("NAO\n");
        return 0;
    }   
    for (int i = 0; i < 3; i++) {
        atual += arr[2 - i][i];
    }
    if (atual == sum) {
        printf("SIM\n");
        return 0;
    } else {
        printf("NAO\n");
        return 0;
    }
}