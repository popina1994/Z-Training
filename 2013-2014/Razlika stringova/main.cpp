#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int lengthmax = 1000000;
char a[lengthmax], b[lengthmax];

int chrtoint(char c) {
    int temp;
    temp = c-'a';
    return temp;
}

char inttochr(int n) {
    int temp;
    temp = 'a'+n;
    return temp;
}

char maxc(int x[]) {
    int max = 0, maxind = -1;
    for (int i = 0; i < 26; i++)
        if (x[i] > max) {
            max = x[i];
            maxind = i;
        }
    return inttochr(maxind);
}

int main() {
    int x[26], sum = 0;
    memset(x, 0, sizeof(x));
    int n, m;
    scanf("%s%s", a, b);
    n = strlen(a);
    m = strlen(b);
//  prolazi nizom a
    for (int i = 0; i < n; i++) {
        x[chrtoint(a[i])]++;
        if (i >= n-m) {
            if (b[i-n+m] == '?')
                b[i-n+m]= maxc(x);
            for (int j = 0; j < 26; j++)
                if (inttochr(j) != b[i-n+m])
                    sum += x[j];
            x[chrtoint(a[i-n+m])]--;

        }
    }
    printf("%s\n%d\n", b, sum);
    return 0;
}
