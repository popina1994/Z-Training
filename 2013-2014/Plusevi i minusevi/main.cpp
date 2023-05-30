#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int kmax = 1000000000;

int x[8][8], k, a[16], b[17];
//  a oznacava koje su kolone i vrste odabrane u promeni
//  b oznacava za promene koliko je najveci broj '+'


double fact(int n) {
    double temp = 1;
    for (int i = 1; i <= n; i++)
        temp *= i;
    return temp;
}

int binkoef(int n, int k) {
    int temp;
    temp = static_cast<int>(fact(n)/(fact(k)*fact(n-k)));
    return temp;
}

void input() {
    for (int i = 0; i < 8; i++) {
        char s[2];
        for (int j = 0; j <8; j++) {
            char tempc;
            tempc = getchar();
            if (tempc == '+')
                x[i][j] = 1;
            else x[i][j] = 0;
        }
        gets(s);
    }
    scanf("%d", &k);
}

void ispis(int x[][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            printf("%d", x[i][j]);
        printf("\n");
    }
}

void setcolomn(int t[][8], int c) {
    for (int i = 0; i < 8; i++)
        t[i][c] = !t[i][c];
}

void setraw(int t[][8],int r) {
    for (int i = 0; i < 8; i++)
        t[r][i] = !t[r][i];
}

int number(int x[][8]) {
    int num = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++){
            num += x[i][j];
            }
    return num;
}

void ispis1(int x[]){
    for (int i = 0; i < 16; i++)
        printf("%d ", x[i]);
    cout << endl;
}

void output() {
    int max = 0;
    b[0] = number(x);
    for (int i = 0+(k%2) ; i < 16 && i <= k; i+=2){
        if (b[i]>max)
            max = b[i];
    }
    printf("%d", max);
}

int main() {
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
     ios_base::sync_with_stdio(0);
    input();
    memset(b, 0, sizeof(b));
    memset(a, 0, sizeof(a));
    for (int i = 0; i < 16; i++) {
        a[i] = 1;
//      prolazi sve moguce permutacije
//      prolazi sve moguce permutacije
        int temp;
        temp = binkoef(16, i+1);
        for (int j = 0; j < temp; j++) {
            int tempmat[8][8];
            memcpy(tempmat, x, sizeof(tempmat));
            next_permutation(a, a+16);
//          nakon nalazenja sledece permutacije podesava kolone i vrste
            for (int k = 0; k < 8; k++) {
                if (a[k] == 1)
                    setraw(tempmat, k);
                if (a[k+8] == 1)
                    setcolomn(tempmat, k);
            }
            int num;
            num = number(tempmat);
            if (b[i+1] < num)
                b[i+1] = num;
        }

    }
    output();
    return 0;

}


