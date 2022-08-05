#include <stdio.h>
int main(){
    int num;
    scanf("%d", &num);
    double grade[num];
    for (int i=0 ; i<num ; i++)
        scanf("%lf", &grade[i]);
    int max=0;
    for(int i=0; i<num; i++)
        if(max < grade[i])
            max = grade[i];
    double sum=0;
    for(int i=0; i<num; i++){
        grade[i] = (double)grade[i]/max*100;
        sum += grade[i];
    }
    printf("%.2f", sum/num);
    return 0;
}