#include <stdio.h>
int main(void)
{
    int arr[9], max=0;
    for(int i=0; i<9; i++){
        scanf("%d", &arr[i]);
        if (max < arr[i])
            max = arr[i];
    }
    printf("%d\n", max);

    for(int j=0; j<9; j++){
        if(max == arr[j])
            printf("%d\n", j+1);
    }
    
    return 0;
}