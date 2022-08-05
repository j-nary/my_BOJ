#include <cstdio>

int dp[1000006];

int tile(int N) {
    if (dp[N] != -1) return dp[N];
    if (N == 1)
        return dp[N] = 1 % 15746;
    else if (N == 2)
        return dp[N] = 2 % 15746;
    return dp[N] = (tile(N-1) + tile(N-2)) % 15746;
}
int main() {
    for (int i = 0; i < 1000006; i++)
        dp[i] = -1;
    int N;
    scanf("%d", &N);
    tile(N);
    printf("%d\n", dp[N]);
    return 0;
    
}