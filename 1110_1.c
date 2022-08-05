#include <stdio.h>
int main(void){
    int n, tmp;
    scanf("%d", &n);
    tmp = n;

    for(int i=0; ; i++){
        n = n%10*10 + (n/10 + n%10)%10;
        if (n==tmp){
            printf("%d\n", i+1);
            break;
        }
    }

    return 0;
}