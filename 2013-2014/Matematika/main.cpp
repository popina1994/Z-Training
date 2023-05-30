#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;

const int n_max = 200;
char s[n_max + 1];
int i = 0, bc = 0;

struct node {
    node *next;
    node *previous;
    int value, cflag, valueflag;
    char c;
    node() : next(NULL), previous(NULL), cflag(0), valueflag(0) {}
    node(int tvalue) : next(NULL), previous(NULL), cflag(0), valueflag(1), value(tvalue) {}
    node(char tc) : next(NULL), previous(NULL), cflag(1), valueflag(0), c(tc) {}
    void operator()(char tc) {
        cflag = 1;
        valueflag = 0;
        c = c;
    }
    void operator()(int tvalue) {
        value = tvalue;
        valueflag = 1;
        cflag  = 0;
    }
    void print() {
        if (valueflag)
            cout << value;
        if (cflag)
            cout << c;
    }
    void deleted () {
        if (next && next->previous )
            next->previous = previous;
        if (previous && previous->next)
            previous->next = next;
    }

};


struct dequeue {
    node *begin, *end;
    dequeue() : begin(NULL) {}
    template <class T>
    void add(T val) {
        if (begin == NULL) {
            begin = new node(val);
            end = begin;
            return;
        }
        node *tbegin = begin;
        while (tbegin->next)
            tbegin = tbegin->next;
        tbegin->next = new node(val);
        end = tbegin->next;
        tbegin->next->previous = tbegin;
        return;
    }
    void print() {
        node *tbegin = begin;
        while (tbegin) {
            tbegin->print();
            tbegin = tbegin ->next;
        }
    }
    node *ending() {
        node *tbegin = begin;
        while (tbegin->next)
            tbegin = tbegin->next;
        return tbegin;
    }

    node *bracketl() {
        node *tbegin = begin;
        while (tbegin){
            if (tbegin->cflag && tbegin->c == ')')
                return tbegin;
                tbegin = tbegin->next;
        }
        return NULL;
    }

    node *bracketr(node *tbegin) {
        while (tbegin) {
            if (tbegin->cflag && tbegin->c == '(')
                return tbegin;
                tbegin = tbegin->previous;
        }
        return NULL;
    }
};



void add_char(dequeue &dq) {
    int number;
    while (s[i] != '=') {
        number = 0;
        if (isdigit(s[i])) {
            for (; isdigit(s[i]); i++)
                number = number * 10 + s[i] - '0';
            dq.add(number);
        } else dq.add(s[i++]);
    }
    dq.add('=');
}

int racunaj_proizvod_deljenje(node *begin) { // kada * i / imaju prioritet
    int sol = begin->value;
    begin->deleted();
    begin = begin->next;
    while(begin->c == '*' || begin->c == '/') {
        if (begin->c == '*')
            sol *= begin->next->value;
        if (begin->c == '/')
            sol /= begin->next->value;
        begin->deleted();
        //brisem prvo znak
        begin->next->deleted();
        //brisem element
        begin = begin->next->next;
    }
    return sol;
}


int add (node *begin, node *end) {
    int sol = 1;
    char nextop;
    if (begin->cflag) {
        if (begin->c == '-')
            sol = -1;
        begin->deleted();
        begin = begin->next;
        //ako ima prefiks
    }
    sol *= begin->value;
    begin->deleted();
    begin = begin->next;
    //brise "pocetak"
    while (begin && begin < end) {
        nextop = begin->next->next->c;
        switch (begin->c) {
        case '+':
            if (nextop == '*' || nextop == '/') {
                sol += racunaj_proizvod_deljenje(begin->next);
                break;
            }
            sol += begin->next->value;
            break;
        case '-':
            if (nextop == '*' || nextop == '/') {
                sol -= racunaj_proizvod_deljenje(begin->next);
                break;
            }
            sol -= begin->next->value;
            break;
        case '/':
            sol = sol / begin->next->value;
            break;
        case '*':
            sol = sol * begin->next->value;
            break;
        }
        begin->deleted();
        begin->next->deleted();
        begin = begin->next->next;
    }
    return sol;
}

int bracket(dequeue &dq) {
    node *tbegin = dq.bracketl(), *tend = dq.bracketr(tbegin);
    int sol;
    while (tbegin) {
        sol = add(tend->next, tbegin->previous);
        (*tend)(sol);
        tbegin->deleted();
        tbegin = dq.bracketl();
        tend = dq.bracketr(tbegin);
        cout << endl;
    }

    dq.end = dq.ending();

    return add(dq.begin, dq.end);
}

int main() {
    dequeue dq;
    char  c;
    freopen("in.in", "r", stdin);
    while (scanf("%c", &c) == 1)
        s[i++] = c;
    s[i] = '\0';
    i = 0;
    add_char(dq);
    int solution = bracket(dq);
    freopen("out.out", "w", stdout);
    printf("%d", solution);
    return 0;
}
