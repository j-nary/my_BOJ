#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("Case #%d: ", i+1);
        printf("%d + %d = %d\n", a, b, a+b);
    }   

    return 0;
}
