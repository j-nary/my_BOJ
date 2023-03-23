//BOJ_12920 평범한 배낭 2
#include <iostream>
#include <algorithm>
#include <vector>

#define weight first
#define value second
using namespace std;

int dp[2][1000006];
int cnt[102];
vector<pair<int, int>> v;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; cin >> N >> M;
    v.push_back({0, 0});
    for (int i = 1; i <= N; i++) {
        int V, C, K;
        cin >> V >> C >> K;
        v.push_back({V, C});
        cnt[i] = K;
    }

    //초기값 설정
    for (int i = 1; i <= cnt[1]; i++) {
        dp[1][v[1].weight * i] = v[1].value * i;
    }
    for (int i = 2; i <= N; i++) {
        //초기화
        for (int j = 0; j <= M; j++) {
            dp[i % 2][j] = 0;
        }
        
        for (int j = 1; j <= M; j++) {
            for (int k = 1; k <= cnt[i]; k++) {
                int idx = j - v[i].weight * k;
                if (idx < 0) break;
                else dp[i % 2][j] = max(dp[(i-1) % 2][j], dp[(i-1) % 2][idx] + v[i].value * k);
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= M; i++) {
        res = max(res, dp[N % 2][i]);
    }
    cout << res << '\n';
}