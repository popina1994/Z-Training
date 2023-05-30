#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
const int n_max = 15;

int x[n_max], sum = 0, i = 0;

int nothing() {
    for (int j = 0; j < i - 1; j++){
        if (x[j] <= sum - x[j])
            return 0;
        sum -= x[j];
    }
    return 1;
}

int main() {
    char c;
    freopen("in.in", "r", stdin);
    while(scanf("%c", &c) == 1 && isdigit(c)) {
        x[i++] = c - '0';
        sum += x[i-1];
    }

    freopen("out.out", "w", stdout);
    printf("%d", nothing());
    return 0;
}
