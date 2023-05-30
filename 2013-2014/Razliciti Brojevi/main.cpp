#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

const int nMax = 100000;

int x[nMax], y[nMax];

void setDiff(int x[], int n, int y[]) {
    int tmpMin = 0, j = 0;
    for (int i = 0; i < n; i ++) {
        y[i] = j;
        if (x[i] > tmpMin) {
            y[i] = ++j;
            tmpMin = x[i];
        }
    }
}

int main() {
    freopen("ulaz.in", "r", stdin);
    freopen("izlaz.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
        scanf("%d", &x[i]);
    setDiff(x, n, y);
    int q, l, r;
    scanf("%d", &q);
    for (int i = 0; i < q; i ++) {
        scanf("%d%d", &l, &r);
        printf("%d\n", y[r] - y[l] + 1);
    }
    return 0;
}
