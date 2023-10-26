#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    char texto[1001];
    char aux[1001];
    scanf(" %d ", &N);
    for (int ctr = 0; ctr < N; ctr++) {
        cin.getline(texto, 1001);
        int len = strlen(texto);
        for (int i = 0; i < len; i++) {
            if ((('a' <= texto[i]) && (texto[i] <= 'z')) || (('A' <= texto[i]) && (texto[i] <= 'Z'))) {
                texto[i] += 3;
            }
        }
        for (int i = 0; i < len; i++) {
            aux[i] = texto[len - 1 - i];
        }
        for (int i = len / 2; i < len; i++) {
            aux[i] -= 1;
        }
        for (int i = 0; i < len; i++) {
            printf("%c", aux[i]);
        }
        printf("\n");
    }
}