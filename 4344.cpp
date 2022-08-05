#include <cstdio>
#include <stdlib.h>

int main() {
    int C;
    scanf("%d", &C);

    for (int i=0; i < C; i++) {
        int N, sum = 0;
        scanf("%d ", &N);
        int *arr = (int *)malloc(sizeof(int) * N);
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[j]);
            sum += arr[j];
        }
        double avg = (double)sum / N;
        int cnt=0;

        for (int j = 0; j < N; j++) {
            if (arr[j] > avg)
                cnt++;
        }
        printf("%.3f%%\n", (float)cnt/N * 100);
    }

    return 0;
}