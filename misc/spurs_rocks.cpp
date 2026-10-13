#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int id, p, pro, con;
} times;

times arr[101];

bool cmp(times a, times b) {
    float avg, bvg;
    if (a.p == b.p) {
        if (a.con == 0) avg = a.pro;
        else avg = (float)a.pro / (float)a.con;
        if (b.con == 0) bvg = b.pro;
        else bvg = (float)b.pro / (float)b.con;

        if (avg == bvg) {
            if (a.pro == b.pro) {
                return a.id < b.id;
            } else {
                return a.pro > b.pro;
            }
        } else {
            return avg > bvg;
        }
    } else {
        return a.p > b.p;
    }
}

int main() {
    bool b = false;
    int n, x, y, z, w, h = 1;
    scanf("%d", &n);
    while (n) {
        if (b) printf("\n");
        b = true;
        memset(arr, 0, sizeof(arr));
        for (int i = 1; i <= n; i++) {
            arr[i].id = i;
        }
        for (int i = 0; i < ((n * (n - 1)) / 2); i++) {
            scanf("%d%d%d%d", &x, &y, &z, &w);
            if (y > w) {
                arr[x].p += 2; arr[x].pro += y; arr[x].con += w;
                arr[z].p += 1; arr[z].pro += w; arr[z].con += y;
            } else {
                arr[x].p += 1; arr[x].pro += y; arr[x].con += w;
                arr[z].p += 2; arr[z].pro += w; arr[z].con += y;
            }
        }
        stable_sort(arr + 1, arr + n + 1, cmp);
        printf("Instancia %d\n", h);
        for (int i = 1; i <= n; i++) {
            printf("%d", arr[i].id);
            if (i != n) printf(" ");
        }
        printf("\n");
        scanf("%d", &n);
        h++;
    }
    return 0;
}