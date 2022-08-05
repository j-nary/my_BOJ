#include <cstdio>

bool dp[1000006][1000006];
int main() {
    int N;
    scanf("%d", &N);
    for (int x = 0; 2*x <= N; x++) {
        int y = N - 2*x;
        dp[x][y] = 1;
    }
    int cnt = 0;
    for (int x = 0; x < 1000006; x++)
        for (int y = 0; y < 1000006; y++) {
            if ( dp[x][y] == 1)
                cnt += y+1;
        }
    printf("%d", cnt % 15746);
    return 0;

}