//BOJ_12865 평범한 배낭 [골드 5]

#include <iostream>
#include <algorithm>
#include <vector>

#define weight first
#define value second

using namespace std;

int dp[2][10000007];
//dp[i][j] : i번째까지 사용했을 때 무게가 j가 되는 가치의 최댓값
vector<pair<int, int> > input;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, K; cin >> N >> K;
    int W, V;
    for (int i = 0; i < N; i++) {
        cin >> W >> V;
        input.push_back(make_pair(W, V));
    }

    //초기값 설정
    dp[0][input[0].weight] = input[0].value;
    //dp 시작
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j-input[i].weight < 0) dp[i%2][j] = dp[(i-1)%2][j];
            else dp[i%2][j] = max(dp[(i-1)%2][j], dp[(i-1)%2][j-input[i].weight] + input[i].value);
        }
    }

    int res = 0;
    for (int i = 0; i <= K; i++) {
        res = max(res, dp[(N-1)%2][i]);
    }
    cout << res << '\n';
}