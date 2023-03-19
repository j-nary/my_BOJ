//BOJ_12865 평범한 배낭 [골드 5]

#include <iostream>
#include <algorithm>
#include <vector>

#define weight first
#define value second

using namespace std;

int dp[2][10000007];
vector<pair<int, int> > input;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, K; cin >> N >> K;
    int W, V;
    for (int i = 0; i < N; i++) {
        cin >> W >> V;
        input.push_back(make_pair(W, V));
    }

    dp[0][input[0].weight] = input[0].value;    //초기값 설정
    int res = input[0].value;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            if (j-input[i].weight < 0) dp[i%2][j] = dp[(i-1)%2][j];
            else dp[i%2][j] = max(dp[(i-1)%2][j], dp[(i-1)%2][j-input[i].weight] + input[i].value);
            if (dp[i%2][j] > res) res = dp[i%2][j];
        }
    }

    cout << res << '\n';
}