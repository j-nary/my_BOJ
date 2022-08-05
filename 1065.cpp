#include <cstdio>

bool check[1003];

int main() {
    int N, cnt=0;
    scanf("%d", &N);
    while(N) {
    if (N < 100)
        cnt++;
    else if (N < 1000 && (N%100/10 - N%10) == (N/100 - N%100/10))
        cnt++;
    N--;
    }

    printf("%d\n", cnt);
    return 0;
}