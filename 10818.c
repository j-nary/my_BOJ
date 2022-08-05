#include <stdio.h>
int main(void)
{
    int num, max=-1000000, min=1000000;
    scanf("%d", &num);
    int arr[num];

    for(int i=0; i<num; i++){
        scanf("%d", &arr[i]);
        if (min > arr[i])
            min = arr[i];
        if (max < arr[i])
            max = arr[i];
    }  
    printf("%d %d\n", min, max);

    return 0;
}