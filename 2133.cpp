#include <iostream>
#include <cstring>
using namespace std;

int dp[31];
int tile(int i) {
    if (i < 0) return 0;
    if (dp[i] != -1) return dp[i];
    else {
        dp[i] = tile(i-2) * 3;
        for (int k = 2; 2*k <= i; k++)
            dp[i] += tile(i - 2*k) * 2;
        return dp[i];
    }
}

int main() {
    int N;
    cin >> N;

    if (N % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;

    cout << tile(N) << endl;    
}