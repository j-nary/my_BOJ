//BOJ_9252 LCS 2 [골드 4]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1003][1003];
vector<int> P[1003][1003];
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
                P[i][j].insert(P[i][j].begin(), P[i-1][j-1].begin(), P[i-1][j-1].end());
                P[i][j].push_back(i);
            } else {
                if (dp[i-1][j] >= dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                    P[i][j].insert(P[i][j].begin(), P[i-1][j].begin(), P[i-1][j].end());
                } else {
                    dp[i][j] = dp[i][j-1];
                    P[i][j].insert(P[i][j].begin(), P[i][j-1].begin(), P[i][j-1].end());
                }
            }
        }
    }

    cout << dp[r - 1][c - 1] << '\n';
    for (int i = 0; i < P[r-1][c-1].size(); i++) {
        cout << s1[P[r-1][c-1][i]];
    }
    cout << '\n';
}