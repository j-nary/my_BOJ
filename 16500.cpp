//BOJ_16500 문자열 판별 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string S;
vector<string> A;
bool dp[102];
int len = 0;

void equalString() {
    for (int i = 0; i < len; i++) {
        if (!dp[i]) continue;
        for (int k = 0; k < A.size(); k++) {
            // cout << A[k].length() << '\n';
            // cout << i + A[k].length() << '\n';
            // cout << len << '\n';
            if (i + A[k].length() > len + 1) continue;
            bool flag = true;
            for (int j = 0; j < A[k].length(); j++) {
                if (S[i + j] != A[k][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) dp[i + A[k].length()] = true;
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> S;
    len = S.length();
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        string ip; cin >> ip;
        A.push_back(ip);
    }

    dp[0] = true;
    equalString();


    cout << dp[len] << '\n';
    return 0;
}