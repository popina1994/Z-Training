#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int nMax = 100, jmpMax = 8, jmpTwoMax = 72, beginR = 36, beginC = 36;

void jmp(int x[][nMax], int r, int c, int lenJmp, int tmpLen){
    if (tmpLen < lenJmp) {
        for (int k = 0; k < jmpMax; k ++)
            jmp(x, r + rJmp[k], c + cJmp[k], lenJmp, tmpLen + 1);
    }
    else if (tmpLen == lenJmp) {
        x[r][c] = 1;
    }
}


int main() {
    freopen("Horse.out", "w", stdout);
    memset(m, 0, sizeof(m));
    jmp(m, beginR, beginC, 1, 0);
    printf("{");
    int counter = 0;
    for (int r = 0; r <= jmpTwoMax; r ++)
        for (int c = 0; c <= jmpTwoMax; c ++)
            if (m[r][c] == 1) {
                printf("%d, ", beginR - r);
                counter ++;
            }
    printf("}\n");
    printf("%d\n", counter);
    printf("{");
    for (int r = 0; r <= jmpTwoMax; r ++)
        for (int c = 0; c <= jmpTwoMax; c ++)
            if (m[r][c] == 1)
                printf("%d, ", beginC - c);
    printf("}");
    return 0;
}
