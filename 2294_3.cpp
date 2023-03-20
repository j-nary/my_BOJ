//BOJ_2294 동전 2 [골드 5]
//뭔가 생각을 잘못한 것 같다.
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> input;
int dp[10004];
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

    fill_n(dp, k + 1, 100005);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = input[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - input[i]] + 1);
        }
    }

    if (dp[k] == 100005) cout << -1 << '\n';
    else cout << dp[k] << '\n';
}