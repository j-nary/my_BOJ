//BOJ_7476 최대 공통 증가 수열 [골드 1]
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

pair<int, int> dp[502][502];    //{개수, 최근 숫자}
vector<int> v1;
vector<int> v2;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    //입력 받기
    int N, input; cin >> N;
    v1.push_back(0);
    for (int i = 0; i < N; i++) {
        cin >> input;
        v1.push_back(input);
    }
    int M; cin >> M;
    v2.push_back(0);
    for (int i = 0; i < M; i++) {
        cin >> input;
        v2.push_back(input);
    }
    
    int maxP = pow(2, 31) * (-1);
    for (int i = 1; i <= N; i++) {
        dp[0][i] = {0, maxP};
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (v1[i] == v2[j] && dp[i - 1][j - 1].second <= v1[i])
                dp[i][j] = {dp[i-1][j-1].first + 1, v1[i]};
            else {
                if (dp[i-1][j].first > dp[i][j-1].first)
                    dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i][j-1];
            }
        }
    }

    cout << dp[N][M].first << '\n';

    vector<int> ans;
    while(dp[N][M].first) {
        if (dp[N][M] == dp[N][M - 1]) M--;
        else if (dp[N][M] == dp[N - 1][M]) N--;
        else {
            ans.push_back(v1[N]);
            N--; M--;
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}