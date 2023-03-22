//BOJ_9252 LCS 2 [골드 4]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1003][1003];
long long P[1003][1003];
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
                P[i][j] = stoi(to_string(P[i-1][j-1])+ "00") + i;
            } else {
                if (dp[i-1][j] >= dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                    P[i][j] = P[i-1][j];
                } else {
                    dp[i][j] = dp[i][j-1];
                    P[i][j] = P[i][j-1];
                }
            }
        }
    }

    cout << dp[r - 1][c - 1] << '\n';
    long long tmp = P[r - 1][c - 1];
    string path = to_string(tmp);
    if (path == "0") return 0;
    for (long long i = 0; i < path.length(); i++) {
        string idx = "";
        while(1) {
            if (i == path.length()) break;
            if (path[i + 1] != '0' && path[i] == '0') {
                break;
            }
            idx.push_back(path[i]);
            i++;
        }
        cout << s1[stoi(idx)];
    }
    cout << '\n';
}