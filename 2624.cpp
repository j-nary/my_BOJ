//BOJ_2625 동전 바꿔주기 [골드 5]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> v;   //{동전 가치, 개수}
long long dp[2][10004];
//dp[i][j] : i번째 동전까지 고려했을 때 합이 j가 되는 경우의 수
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int P; cin >> P;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i <= v[0].second; i++) {
        dp[0][v[0].first * i] = 1;
    }
    for (int i = 1; i < v.size(); i++) {
        for (int j = 0; j <= P; j++) {
            dp[i%2][j] = dp[(i-1)%2][j];
            for (int cnt = 1; cnt <= v[i].second; cnt++) {
                if (j - v[i].first*cnt < 0) continue;
                dp[i%2][j] += dp[(i - 1) % 2][j - v[i].first*cnt];
            }
            // cout << dp[i%2][j] << " ";
        }
        // cout << '\n';
    }

    cout << dp[(N - 1) % 2][P] << '\n';
}