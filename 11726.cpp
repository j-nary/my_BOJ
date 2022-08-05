#include <cstdio>

int dp[1003];

int square(int N) {
    if (dp[N] != -1) return dp[N];
    else if (N == 1)
        return dp[N] = 1 % 10007;
    else if (N == 2)
        return dp[N] = 2 % 10007;
    return dp[N] = (square(N-1) + square(N-2)) % 10007;
}
int main() {
    for (int i = 0 ; i < 1003; i++)
        dp[i] =-1;
    int N;
    scanf("%d", &N);
    square(N);
    printf("%d\n", dp[N]);
    return 0;
}