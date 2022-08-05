#include <stdio.h>

int main() {
    int A, B, C;
    scanf ("%d %d %d", &A, &B, &C);
    
    long long i = 1;

    while(1){
        if (B >= C) {
            printf("-1");
            return 0;
        }
        if (A + B*i < C*i){
            printf("%lld", i);
            return 0;
        }
        i++;
    }

    return 0;
}