#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);

    for(int k=0; k<n; k++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a+b);
    }

    return 0;
}
