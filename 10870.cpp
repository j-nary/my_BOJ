#include <cstdio>

int fibo(int);

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", fibo(n));
}

int fibo(int n) {
    if (n == 0)
        return 0;
    if (n <= 2)
        return 1;
    else
       return fibo(n-1) + fibo(n-2);
}

