#include <stdio.h>
#include <string.h>
int main(){
    int num, i=0, k=0, p=0;
    scanf("%d", &num);
    char arr[100];
    int sum[100] = {0};
    
    while(i != num){
        scanf("%s", arr);
        k=0;
        int size = strlen(arr);
        for(int j=0; j<size ; j++){
            if (arr[j] == 'O')
                sum[p] += ++k;
            else if (arr[j] == 'X')
                k=0;
            // if (arr[j] == '\n')
            //     break;
        }
        i++;
        p++;
    }

    for(int i=0; i<num; i++)
        printf("%d\n", sum[i]);
    
    return 0;
}