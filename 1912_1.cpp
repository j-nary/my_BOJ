#include <iostream>

using namespace std;

int dp[100005];
int Data[100005];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> Data[i];

    dp[n-1] = Data[n-1];

    for ( int i = n-2; i >= 0; i--) {
        if (dp[i+1] + Data[i] > Data[i])
            dp[i] = dp[i+1] + Data[i];
        else dp[i] = Data[i];
    }

    int max = dp[0];
    for (int i = 1; i < n; i++)
        if (max < dp[i]) max = dp[i];
    
    cout << max << endl;

}