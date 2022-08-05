#include <iostream>
#include <cstring>
using namespace std;

int dp[5000];
int main() {
    int N;
    cin >> N;

    memset(dp, -1, sizeof(dp));

    dp[3] = 1;
    dp[5] = 1;

    for (int i = 6; i <= N; i++) {
        if (dp[i-3] != -1 && dp[i-5] != -1)
            dp[i] = min(dp[i-3], dp[i-5]) + 1;
        else if (dp[i-3] != -1)
            dp[i] = dp[i-3] + 1;
        else if (dp[i-5] != -1)
            dp[i] = dp[i-5] + 1;
        else {
            dp[i] = -1;
        }
    }
    
    // for (int i = 0 ; i <= N; i++)
    //     cout << "dp[" << i << "] = " << dp[i] << "  ";
    
    // cout << endl;
    cout << dp[N] << endl;
}