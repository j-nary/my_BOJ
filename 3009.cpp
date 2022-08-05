#include <stdio.h>
int main() {
    int arr[1003] = {0};
    int tmp;
    for (int i = 0; i < 6; i++) {
        scanf("%d", &tmp);
        arr[tmp]++;
    }
    int dot[1];
    int j = 0;
    for (int i = 0; i < 1000; i++) {
        if ( arr[i] == 1 || arr[i] == 3) {
            dot[j] = i;
            j++;
            arr[0]++;
        }
    }
    if ( arr[0] == 0 ) {
        for (int i = 0; i < 1000; i++) {
            if (arr[i] == 2)
                tmp = i;
        }
        printf("%d %d", tmp, tmp);
    }
    else
        printf("%d %d", dot[0], dot[1]);

    return 0;

}