#include <iostream>
#include <cstring>
using namespace std;

int dp[1003][11];

int password(int N, int i) {
    if (dp[N][i] != -1) return dp[N][i] % 1234567;
    else if (i == 0) return dp[N][0] = dp[N-1][7] % 1234567;
    else if (i == 1) 
        return dp[N][1] = (password(N - 1,2) + password(N - 1,4)) % 1234567;
    else if (i == 2)
        return dp[N][2] = (password(N - 1, 1) + password(N - 1, 3) + password(N - 1, 5)) % 1234567;
    else if (i == 3)
        return dp[N][3] = (password(N - 1, 2) + password(N - 1, 6)) % 1234567;
    else if (i == 4)
        return dp[N][4] = (password(N - 1,1) + password(N - 1,5) + password(N - 1,7)) % 1234567;
    else if (i == 5)
        return dp[N][5] = (password(N - 1,2) + password(N - 1,4) + password(N - 1,6) + password(N - 1,8)) % 1234567;
    else if (i == 6)
        return dp[N][6] = (password(N - 1,3) + password(N - 1,5) + password(N - 1,9)) % 1234567;
    else if (i == 7)
        return dp[N][7] = (password(N - 1,0) + password(N - 1,4) + password(N - 1,8)) % 1234567;
    else if (i == 8)
        return dp[N][8] = (password(N - 1,5) + password(N - 1,7) + password(N - 1,9)) % 1234567;
    else
        return dp[N][9] = (password(N - 1,6) + password(N - 1,8)) % 1234567;
}

int main() {
    int T;
    cin >> T;

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
    
    while(T--) {
        int N;
        cin >> N;
        
        int sum = 0;
        for (int i = 0; i < 10; i++)
            sum = (sum + password(N, i)) % 1234567;
        
        cout << sum << endl;
/*
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < 10; j++)
                cout << dp[i][j] << "   ";
            cout << endl;
        }
        */
    }
}