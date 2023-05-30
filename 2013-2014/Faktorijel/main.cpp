#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int n_max = 24;

unsigned long long fakt(long long n) {
    unsigned long long product = 1;
    if (n == 0)
        return 1;
    for (int i = 1; i <= n; i++)
        product *= i;
    return product;
}

int main() {
    int n;
    freopen("in.in", "r", stdin);
    scanf("%d", &n);
    freopen("out.out", "w", stdout);
    printf("%ulld", fakt(n));
    return 0;
}
