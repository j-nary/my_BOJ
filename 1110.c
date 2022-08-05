#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n, k=0;
    scanf("%d", &n);
    int tmp=n ;
    int arr[999];

    arr[0] = n/10 + n%10;

    for(int i=1; ; i++){
        arr[i] = tmp%10*10 + arr[i-1]%10;
        tmp = arr[i]%10;
        if(arr[i] == n){
            printf("%d", i+1);
            break;
        }
    }

    return 0;
}