#include <cstdio>

bool arr[300005];
int main(){
    int n, start, end;
    arr[1] = true;
    while(1){
        scanf("%d", &n);
        if(n==0)
            break;
        start = n+1; end = 2*n;

        for(int i=2; i*i <= end; i++){
            if(arr[i] == false){
                for(int j=i*i; j <= end; j+=i)
                    arr[j] = true;
            }        
        }

        int k=0;
        for(int i=start; i<=end; i++)
            if(arr[i]==false)
                k++;
        printf("%d\n", k);
    }
    return 0;
}