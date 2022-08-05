#include <stdio.h>

int max( int a, int b, int c) {
    int tmp = a;
    if ( b > a)
        tmp = b;
    if ( c > b && c > a)
        tmp = c;
    return tmp;
}
int main() {
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);

    if (a == b && b == c) {
        printf("%d", 10000 + a*1000);
        return 0;
    }
    int k = 0;

    if ( a != b && b != c && c != a){
        printf("%d", max(a, b, c)*100);
        return 0;
    }

    if (a==b) k = a;
    else if (a == c) k = a;
    else if (b == c) k = b;

    printf("%d", 1000 + k*100);
    return 0;
}