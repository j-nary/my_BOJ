//BOJ_14002 가장 긴 증가하는 부분 수열 4 [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int A[1003];
int dp[1003];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < 1003; i++) dp[i] = 1;
    int cnt = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] <= A[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                cnt = max(cnt, dp[i]);
            }
        }
    }
    
    cout << cnt << '\n';
    vector<int> v;
    for (int i = N - 1; i >= 0; i--) {
        if (dp[i] == cnt) {
            v.push_back(A[i]);
            cnt--;
        }
        if (cnt <= 0) break;
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }
    cout << '\n';
}

// 1 2 2 3 3 4