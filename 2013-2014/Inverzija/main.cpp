    #include <iostream>
    #include <cstdio>
    #include <cstring>

    using namespace std;

    const int maxlength = 1e6;

    char a[maxlength+1], b[maxlength+1];
    int n;
    int chrtoint(char c){
        return (c - '0');
    }

    int main(){
        int ld = 0, count = 0;
        // count broji koliko ima razlicitih podnizova, ld da li je poslednji razlicit
        scanf("%s%s", &a, &b);
        n = strlen(a);
        for(int i = 0; i < n; i++){
            if (a[i] != b[i] && !ld){
                ld = 1;
                count++;
            }
            if (a[i] == b[i])
                ld = 0;
        }
        printf("%d", count);
        return 0;
    }
