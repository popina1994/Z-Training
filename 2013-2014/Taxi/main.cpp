#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n_max = 1e5, temp, count[3], counter = 0;


int main() {
    freopen("in.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", temp);
        if (temp == 4)
            counter ++;
        if (temp == 3 && count[0] > 0)
            counter ++;
        if (temp == 2 && count[1] > 0)
            counter


    }

    return 0;
}
