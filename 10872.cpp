#include <cstdio>

int fac(int);

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0)
        printf("1\n");
    else
        printf("%d\n", fac(n));

    return 0;
}

int fac(int n) {
    if (n != 1){
        n *= fac(n-1);
    return n;
    }
    
    return n;
}