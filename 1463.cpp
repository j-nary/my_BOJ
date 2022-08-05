#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;

    ll dp[1000006][1000006];
    memset(dp, -1, sizeof(dp));

    dp[0][0] = N;

    int i = 1; int j = 0;
    for (int i = 1; ; i++)
        for (int j = 0; j < i^3; j++) {
            if (dp[i-1][j/3] == 1) {
                cout << j-1 << endl;
                return 0;
            }
            if (dp[i-1][j/3] % 3 == 0)
                dp[i][j] = dp[i-1][j/3] / 3;
            if (dp[i-1][j/3] % 2 == 0)
                dp[i][j+1] = dp[i-1][j/3] / 2;
            dp[i][j+2] = dp[i-1][j/3] - 1;
        }    
}