#include <stdio.h>
int main(){
    int a, b, c;
    scanf("%d\n%d\n%d", &a, &b, &c);

    int result;
    result = a * b * c;

    int num[10] = {0};

    while(result != 0){     //result라 해도 됨!
        int k = result % 10 ;
        result = result / 10;
        num[k]+=1;
    }

    for(int i=0; i<10; i++){
        printf("%d\n", num[i]);
    }

    return 0;
}