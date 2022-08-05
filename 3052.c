#include <stdio.h>
int main(){
    int num[10]={0};
    for(int i=0; i<10; i++){
        scanf("%d", &num[i]);
        num[i] = num[i] % 42;
    }
   int k=10 ;
   for(int i=0; i<10; i++){
       for(int j=0; j<i; j++)
            if(num[i] == num[j]){
                k--;
                break;
            }
   }
   printf("%d\n", k);
   return 0;
}