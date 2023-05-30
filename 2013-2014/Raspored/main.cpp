#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

struct profesor {
    char ime[100] = "";
    char prezime[100]= "";
};

class profesori {
public :
    profesor x[100];
    int trbr;
public:void ubaciime(char s[100], int n);
public:void ubaciprezime(char s[100], int n);
public:void change(int n);
public:void changens();
public :void print();
};


void profesori::ubaciime(char s[], int n) {
    memcpy(x[n].ime, s, strlen(s)+1);
}

void profesori::ubaciprezime(char s[], int n) {
    memcpy(x[n].prezime, s, strlen(s)+1);

}

void profesori::change(int n) {
    trbr = n;
}

profesori y;

void profesori::changens() {
    char c;
    while (c != 'k') {//nesto sto nece biti
        int n;
        printf("ako zelite kraj pritisnite k\nako zelite promenu imena ili prezimena pritisnite c\n");
        scanf("%c", &c);
        if (c == 'k') break;
        printf("unesite id:\n");
        scanf("%d", &n);
        printf("ako zelite ime pritisnite i\nako zelite prezime pritisnite p\n");
        scanf("%c%c", &c, &c);
        char s[100];
        if (c == 'i') {
            printf("unesite ime bez razmaka\n");
            scanf("%s%c", &s, &c);
            y.ubaciime(s, n);
        }
        if (c == 'p') {
            printf("unesite prezime bez razmaka\n");
            scanf("%s%c", &s, &c);
            y.ubaciprezime(s, n);
        }
    }
    printf("kraj");
}


void readpr() {
    freopen("profesor.in", "r", stdin);
    int n;
    scanf("%d", &n);
    y.change(n);
    for (int i = 0; i < n; i++) {
        char s1[100],s2[100];
        scanf("%s%s", &s1, &s2);
        y.ubaciime(s1, i);
        y.ubaciprezime(s2, i);
    }
    fclose(stdin);
    freopen("CON", "r", stdin);
}

void writep() {
    freopen("profesor.in", "w", stdout);
    printf("%d\n", y.trbr);
    for (int i = 0; i < 100; i++) {
        printf("%s %s\n", y.x[i].ime, y.x[i].prezime);
    }
    fclose(stdout);
}

int main() {
    readpr();
    y.changens();
    writep();
    return 0;
}
