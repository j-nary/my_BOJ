#include <stdio.h>
int main(void)
{
    int p,q=0, num;
    scanf("%d", &num);
    for(int i=1; i<=num; i++){
        q+=i;
    }
    printf("%d\n", q);

    return 0;
}
