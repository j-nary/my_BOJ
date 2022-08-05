#include <iostream>
#include <algorithm>

using namespace std;

int dp[1003][1003];
int main() {
    string s1; string s2;
    cin >> s1 >> s2;
    s1 = "5" + s1; s2 = "1" + s2;
    int cnt = 0;
    for (int i = 1; i < s1.length(); i++) {
        for (int j = 1; j < s2. length(); j++) {
            if (s1[i] == s2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (dp[i][j] > cnt) cnt = dp[i][j];
        }
    }

    cout << cnt << endl;
}