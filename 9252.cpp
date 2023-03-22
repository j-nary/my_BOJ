//BOJ_9252 LCS 2 [골드 4]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1003][1003];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;
    s1 = "5" + s1;
    s2 = "2" + s2;

    int r = s1.length();
    int c = s2.length();
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                if (dp[i-1][j] >= dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }

    cout << dp[--r][--c] << '\n';
    
    string res = "";
    while(dp[r][c]) {
        if (dp[r][c] == dp[r - 1][c]) r--;
        else if (dp[r][c] == dp[r][c - 1]) c--;
        else {
            res += s1[r];
            r--, c--;
        }
    }
    if (res.size() > 0) {
        reverse(res.begin(), res.end());
        cout << res << '\n';
    }
}