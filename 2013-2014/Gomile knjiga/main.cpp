#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

const int n_max = 50;

int x[n_max][n_max], y[n_max][n_max], n;

int ret(int x[][n_max], int i, int j, int type)
{
    if (type == 0)
        return (x[i][j]);
    if (type == 1)
        return x[j][i];
    if (type == 2)
        return x[n-1-i][n-1-j];
    if (type == 3)
        return x[n-1-j][n-1-i];
}

void set(int i, int j, int type)
{
    switch(type)
    {
    case 0:
        y[i][j] = 1;
        return;
    case 1:
        y[j][i] = 1;
        return;
    case 2:
        y[n-1-i][n-1-j] = 1;
        return;
    case 3:
        y[n-1-j][n-1-i] = 1;
        return;
    }
}

void ispis(int x[][n_max])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << x[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int counter = 0;
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    memset(y, 0, sizeof(x));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &x[i][j]);
    int temp[4];
    // temp ce oznacavati koja je vrednost, tempcan, da li moze da ide "dalje"
    int value;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < 4; k++)
            temp[k] = 0;
        for (int j = 0; j < n; j++)
            for (int k = 0; k < 4; k++)
            {
                value = ret(x, i, j, k);
                if (value > temp[k])
                {
                    temp[k] = value;
                    if (ret(y, i, j, k) == 0)
                    {
                        counter++;
                        set(i, j, k);
                    }
                }
            }
    }
    printf("%d", counter);
    return 0;
}
