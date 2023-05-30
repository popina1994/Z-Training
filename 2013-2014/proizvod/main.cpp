#include <iostream>
using namespace std;

int main()
{
    int p = 1;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)  {
       p *= i;
       while (p % 10 ==0 )
            p /= 10;
       p %= 100000;
    }
    cout << p % 10<< endl;
    return 0;
}
