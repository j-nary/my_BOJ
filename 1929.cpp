#include <cstdio>

bool arr[1000006];
int main(){
    int start, end;
    arr[1] = true;
    scanf("%d %d", &start, &end);
    for(int i=2; i*i <= end; i++){
        if(arr[i] == false){
            for(int j=i*i; j <= end; j+=i)
                arr[j] = true;
        }        
    }

    for(int i=start; i<=end; i++)
        if(arr[i]==false)
            printf("%d\n", i);
    return 0;
}