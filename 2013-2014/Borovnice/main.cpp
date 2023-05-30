#include <iostream>
#include <cstdio>

using namespace std;

const int nmax = 100000;
const int qmax = 1000000;
int  x[nmax], n, q, question[qmax];
long long min(long long x, long long y) {
    if (x>y)
        return(y);
    return x;
}


int main() {
    long long sumfirst = 0, sumsecond = 0;
    scanf("%d%d ", &n, &q);
//    cita n i q i niz
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    for (int i = 0; i < n; i++)
        sumsecond += x[i];
    int tempmin = 0;
    for (int i = 0; i < n-1; i++) {
        sumfirst += x[i];
        sumsecond -= x[i];
        if (min(sumfirst, sumsecond) > tempmin)
            tempmin = min(sumfirst, sumsecond);
    }
    for (int i = 0; i < q; i++)
        scanf("%d", &question[i]);
    for (int i = 0; i < q; i++)
        if (tempmin > question[i])
            printf("d\n");
        else printf("n\n");
    return 0;
}
