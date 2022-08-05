#include <iostream>
#include <cstring>

using namespace std;

string s1;
string s2;
string tgt;

int dp[202][202];

//.length()보다는 전역변수로 s1_len = s1.length() 저장해두고 쓰는 게 더 GOOD~~!

bool dfs(int left, int right) {
    int curr = left + right;

    if (dp[left][right] != -1) return dp[left][right];

    if (curr == tgt.length() && left >= s1.length() && right >= s2.length()) {
        dp[left][right] = 1;
        return true;
    }

    if (s1[left] == tgt[curr]) {
        if (dfs(left + 1, right)) {
            dp[left][right] = 1;
            return true;
        }
    }
    if (s2[right] == tgt[curr]) {
        if (dfs(left, right + 1)) {
            dp[left][right] = 1;
            return true;
        }
    }

    dp[left][right] = 0;
    return false;
}

int main() {
    int T; cin >> T;

    bool yn = false;
    for (int i = 1; i <= T; i++) {
        cin >> s1 >> s2 >> tgt;
        memset(dp, -1, sizeof(dp));
        int left = 0;
        int right = 0;

        cout << "Data set " << i << ": ";

        if (dfs(left, right)) cout << "yes" << endl;
        else cout << "no" << endl;        
    }

    // for (int i = 0; i <= s1.length(); i++) {
    //     for (int j = 0; j <= s2.length(); j++) {
    //         cout << dp[i][j] << "   ";
    //     }
    //     cout << endl;
    // }
}