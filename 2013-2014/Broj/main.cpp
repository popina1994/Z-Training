#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int n_max = 15;

int main() {
    char c, s[n_max];
    int x[n_max], i = 0;
    freopen("in.in", "r", stdin);
    while (scanf("%c", &c) && isdigit(c))
        s[i++] = c;
    s[i] = '\0';

    for (int j = 0; j < i; j++)
        x[j] = s[j] - '0';
    sort(x, x + i );
    freopen("out.out", "w", stdout);
    for (int j = 0; j < i; j++)
       cout << x[j];
    return 0;
}
