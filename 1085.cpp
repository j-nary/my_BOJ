#include <stdio.h>
int main() {
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    int arr[4] = {x, y, w-x, h-y};
    int tmp = arr[0];
    for ( int i = 1; i < 4; i++) {
        if ( tmp > arr[i] && arr[i] > 0)
            tmp = arr[i];
    }
    printf("%d\n", tmp);
    return 0;
}