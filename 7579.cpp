//BOJ_7579 앱 [골드 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> A;  //활성화 되어있는 앱이 사용 중인 메모리의 바이트 수
vector<int> C;  //각 앱을 비활성화 했을 경우의 비용

int dp[102][10004];  //dp[i][j] : i번째 앱까지 확인했을 때 j비용으로 얻을 수 있는 최대의 메모리

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        A.push_back(input);
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        C.push_back(input);
        sum += input;
    }

    for (int i = C[0]; i <= sum; i++) {
        dp[0][i] = A[0];
    }
    for (int i = 1; i < A.size(); i++) {
        for (int j = 0; j <= sum; j++) {
            if (j - C[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - C[i]] + A[i]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    for (int i = 0; i <= sum; i++) {
        if (dp[N - 1][i] >= M) {
            cout << i << '\n';
            return 0;
        }
    }
}