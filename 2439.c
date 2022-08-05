#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int i, j=0, k;
    for(i=0; i<n; i++){
        for(k=0; k<n-1-j; k++)
            printf(" ");
        for(j=0; j<i+1; j++)
            printf("*");
        printf("\n");
    }   

    return 0;
}

