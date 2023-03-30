//BOJ_1937 욕심쟁이 판다 [골드 3]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int map[502][502];
int dp[502][502];
int res;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dpPanda(int i, int j) {
    if (dp[i][j] != 0) return dp[i][j];

    dp[i][j] = 1;
    for (int dir = 0; dir < 4; dir++) {
        int x = i + dx[dir];
        int y = j + dy[dir];

        if (map[x][y] == 0) continue;
        if (map[i][j] < map[x][y]) dp[i][j] = max(dp[i][j], dpPanda(x, y) + 1);
    }

    res = max(res, dp[i][j]);
    return dp[i][j];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dp[i][j] == 0) {
                dpPanda(i, j);
            }
        }
    }

    cout << res << '\n';
}