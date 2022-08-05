#include <stdio.h>
int main() {
    int num, sum = 0;
    scanf("%d", &num);
    int arr[101];
    for (int i = 0; i < num; i++) {
        scanf("%1d", &arr[i]);
        sum += arr[i];
    }
    printf("%d", sum);
    return 0;
}