#include <iostream>
#include <fstream>
#include <cstring>
#define stop system("pause");
using namespace std;

const int nmax = 100001;
int n, x[nmax], y[nmax], z[nmax], posi[nmax];
// x pocetni niz, y oznacava da li je element vec 'zamenjen', posi oznacava poziciju i-tog broja u nizu x, z izlazni niz
void input(){
    ifstream f("problema.in");
    f >> n;
    for (int i = 1; i <= n; i++){
        f >> x[i];
        posi[x[i]] = i;
    }
    f.close();
}
void set(){
    memset(y, 0, sizeof(y));
    }

void loading(){
    for (int i = 1; i <= n; i++)
        if (x[i] != 1 && (y[x[i]] == 0) && (y[x[i]- 1] == 0)){
            y[x[i]] =  y[x[i] - 1] = 1;
            z[i] = x[i] - 1;
            z[posi[x[i] - 1]] = x[i];
        }
        else    if (y[x[i]] != 1){
                    y[x[i]] = 1;
                    z[i] = x[i];
                }
}



void output(){
    ofstream f("problema.out");
    for (int i = 1; i <= n; i++)
        f << z[i] << " ";
    f << endl;
    f.close();
}

int main(){
    input();
    loading();
    output();
    return (0);
}
