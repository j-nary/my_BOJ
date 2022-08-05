#include <iostream>
#include <cstring>

using namespace std;

int dp[1003];
int main() {
    string s1, s2;
    cin >> s1 + 1 >> s2 + 1;

    for (int i = 1; i < s1.length(); i++) {
        int flag = 0;
        for (int j = 1; j < s2.length(); j++) {
            if (s1[i] == s2[j])
                dp[j] = flag + 1;
            else if (dp[j] > flag) 
                flag = dp[j];
        }
    }

    int cnt = 0;
    for (int i = 1; i < s2.length(); i++) {
        if (cnt < s2[i]) cnt = s2[i];
    }

    cout << cnt << endl;
}