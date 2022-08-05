#include <iostream>

// dp 쓰지않아서 시간초과남
using namespace std;

int dp[100005];
int Data[100005];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> Data[i];

    int max;
    for (int i = 0; i < n; i++) {
        max = Data[i];
        int sum = Data[i];
        for (int j = i + 1; j < n; j++) {
            sum += Data[j];
            if ( sum > max ) max = sum;
        }
        dp[i] = max;
    }

    max = dp[0];
    for (int i = 1; i < n; i++) {
        if (max < dp[i]) max = dp[i];
    }

    cout << max << '\n';
    return 0;
}