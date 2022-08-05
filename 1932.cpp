#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int samgak[502][502];
int dp[502][502];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= i; j++) {
            cin >> samgak[i][j];
            dp[i][j] = 0;
        }

    dp[1][1] = samgak[1][1];

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= i; j++) {
            if (dp[i-1][j] != -1 && dp[i-1][j-1])
                dp[i][j] = samgak[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
            else if (dp[i-1][j] != -1) dp[i][j] = samgak[i][j] + dp[i-1][j];
            else if (dp[i-1][j-1] != -1) dp[i][j] = samgak[i][j] + dp[i-1][j-1];
        }

    int max = dp[n][1];
    for (int i = 2; i <= n; i++) {
        if (max < dp[n][i]) max = dp[n][i];
    }

    cout << max << endl;

}