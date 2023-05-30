#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int binomial(int n, int k) {

    double sol = 1;
    for (int i = 0; i < k; i++){
        sol = sol * (n - i) / (i + 1);
    }
    return int(sol);
}

int main() {
    int n, k;
    freopen("in.in", "r", stdin);
    scanf("%d %d", &n, &k);
    freopen("out.out", "w", stdout);
    printf("%d", binomial(n, k));
    return 0;
}
