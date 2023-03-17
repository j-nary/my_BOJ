//BOJ_12865 평범한 배낭 [골드 5]
#include <iostream>
#include <algorithm>
#include <vector>

#define weight first
#define value second
using namespace std;

vector<pair<int, int>> input;
int dp[2][1003];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    //입력 받기
    int N, K;
    cin >> N >> K;
    int w, v;
    for (int i = 0; i < N; i++) {
        cin >> w >> v;
        input.push_back({w, v});
    }

    //dp[i][j] : i번째 수를 넣었을 때 가치가 j가 되는 최소의 무게값
    //초기값 설정
    dp[0][input[0].value] = input[0].weight;

    for (int i = 1; i < N; i++) {
        //초기화
        for (int k = 0; k <= 1003; k++) {
            dp[i%2][k] = 0;
        }

        for (int j = 0; j <= 1003; j++) {
            dp[i%2][j] = dp[(i-1)%2][j];
            if (j - input[i].value < 0) {
                if (dp[i%2][j] != 0) cout << "i = " << i << " -> dp[" << i%2 << "][" << j << "]=" << dp[i%2][j] << '\n';
                continue;
            }
            int tmp =  dp[(i-1)%2][j - input[i].value] + input[i].weight;
            if (tmp > K) continue;
            dp[i%2][j] = min(dp[(i-1)%2][j], tmp);
            if (dp[i%2][j] != 0) cout << "i = " << i << " -> dp[" << i%2 << "][" << j << "]=" << dp[i%2][j] << '\n';
        }
    }

    int res = 0;
    for (int i = 0; i < 1003; i++) {
        if (K >= dp[(N-1)%2][i] && dp[(N-1)%2][i] > 0) {
            res = i;
        }
    }

    cout << res << '\n';
}