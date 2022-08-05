#include <stdio.h>

int main() {
    int h, m, p;
    scanf("%d %d %d", &h, &m, &p);
    if (m+p <60) {
        printf("%d %d", h, m+p);
        return 0;
    }
    int tmp = m+p;
    while (tmp >= 60) {
        h++;
        tmp -= 60;
    }
    if(h >= 24)
        h-=24;
    printf("%d %d", h, tmp);
    return 0;
}