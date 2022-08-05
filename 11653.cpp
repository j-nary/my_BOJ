#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int i = 2;
    while(N != 1) {
        while(1) {
            if (N % i == 0) {
                printf("%d\n", i);
                N = N / i;
            }
            else
                break;
        }
        i++;
    }

    return 0;
}