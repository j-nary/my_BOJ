//BOJ_2294 동전 2 [골드 5]
//잘못해도 한참 잘못한 문제풀이법
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[10004];
vector<int> input;
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

    for (int i = 0; i < n; i++) {
        for (int j = 1; ; j++) {
            int idx = input[i] * j;
            if (idx > k) break;
            dp[idx] = j;
        }
    }

    if (dp[k] == 0) cout << -1 << '\n';
    else cout << dp[k] << '\n';
}