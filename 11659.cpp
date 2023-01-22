//BOJ_11659 구간 합 구하기 4 [실버 3]
//https://www.acmicpc.net/problem/11659
//메모리 초과!!

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100005];
int dp[100005][100005];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if (dp[a][b]) {
            cout << dp[a][b] << endl;
            continue;
        }
        int cnt = 0;
        for (int j = a; j <= b; j++) {
            cnt += arr[j];
        }
        dp[a][b] = cnt;
        cout << cnt << endl;
    }

}