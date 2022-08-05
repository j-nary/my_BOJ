#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int L[22];
int J[22];

int dp[21][101];

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        cin >> L[i];
    }
    for (int i = 1; i <= T; i++) {
        cin >> J[i];
    }

    for (int i = 0; i <= T; i++) {
        for (int j = 0; j <= 100; j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (L[i] >= j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-L[i]] + J[i]);
        }
    }

    cout << dp[T][100] << endl;
        
}