#include <cstdio>

int dp[100];
int dp2[100];

int fibo(int N) {
    if (dp[N] != -1) return dp[N];
    if (N == 0) {
        return dp[0] = 0;
    }
    else if (N == 1) {
        return dp[1] = 1;
    }
    else return dp[N] = fibo(N-1) + fibo(N-2);
}
int fibo2(int N) {
    if (dp2[N] != -1) return dp2[N];
    if (N == 0) {
        return dp2[0] = 1;
    }
    else if (N == 1) {
        return dp2[1] = 0;
    }
    else return dp2[N] = fibo2(N-1) + fibo2(N-2);
}

int main() {
    for (int i = 0; i < 100; i++)
        dp[i] = dp2[i] = -1;
    int T;
    scanf("%d", &T);
    while(T--) {
        int N;
        scanf("%d", &N);
        fibo(N);
        fibo2(N);
        printf("%d %d\n", dp2[N], dp[N]);
    }
    return 0;
}