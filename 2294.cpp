//BOJ_2294 동전 2 [골드 5]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> input;
int dp[2][10004];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    //입력받기
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        input.push_back(tmp);
    }
    //가치가 같은 동전이 여러 번 주어질 수 있으니 중복 제거
    sort(input.begin(), input.end());
    input.erase(unique(input.begin(), input.end()), input.end());

    dp[0][0] = 1;
    bool flag = 1;
    for (int i = 0; input[0]*i <= k; i++) {
        dp[0][input[0]*i] = i;
    }

    for (int i = 1; i < n; i++) {
        flag = !flag;
        for (int j = 0; j <= k; j++) {
            dp[i%2][j] = 0;     //초기화
        }
        for (int j = 0; j <= k; j++) {
            dp[i%2][j] = dp[(i-1)%2][j];
            for (int cnt = 0; ; cnt++) {
                int tmp = j-input[i]*cnt;
                if (tmp < 0) break;
                else if (dp[(i-1)%2][j] != 0) {
                    dp[i%2][j] = min(dp[(i-1)%2][j], dp[(i-1)%2][tmp] + cnt);
                }
            }
        }
    }

    if (dp[0][k] == 0 && dp[1][k] == 0) {
        cout << -1 << '\n';
    }
    else {
        cout << dp[flag][k] << '\n';
    }
}