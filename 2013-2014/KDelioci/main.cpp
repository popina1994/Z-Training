#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n, m = 0;
    float arsum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n/2; i++)
        if (n % i == 0){
            arsum += i;
            m++;
        }
    m++;
    arsum += n;
    arsum /= m;
    printf("%.2f", arsum);
    return 0;
}
