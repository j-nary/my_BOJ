#include <cstdio>

bool arr[10004];

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    arr[0] = true;
    arr[1] = true;
    for (int i=2; i*i <= N; i++) {
        if (arr[i] == false) {
            for (int j = i*i; j <= N; j += i)
                arr[j] = true;
        } 
    }

    int sum = 0;

    for (int i=M; i <= N; i++) {
        if (arr[i] == false) {
            sum += i;
        }
    }
    if (sum == 0) {
        printf("-1\n");
        return 0;
    }
    else printf("%d\n", sum);

    for (int i=M; i <= N; i++) {
        if (arr[i] == false) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}