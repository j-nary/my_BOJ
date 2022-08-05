#include <stdio.h>
int main() {
    int x[1003] = {0};
    int y[1003] = {0};
    int tmp = 0;
    for (int i = 0; i < 3; i++) {
        scanf("%d", &tmp);
        x[tmp]++;
        scanf("%d", &tmp);
        y[tmp]++;
    }
    int dot[1];
    for (int i = 0; i < 1003; i++) {
        if (x[i] == 1) {
            dot[0] = i;
        }
        if (y[i] == 1) {
            dot[1] = i;
        }
        if (dot[0] != 0 && dot[1] != 0) {
            break;
        }
    }
    printf("%d %d", dot[0], dot[1]);
    return 0;
    
       
}