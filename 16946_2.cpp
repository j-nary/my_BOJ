//BOJ_16946 벽 부수고 이동하기 4 [골드 2]
//시간초과
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int N, M;
int map[1003][1003];
bool chk[1003][1003];
int cnt;

void dfs (int r, int c) {
    chk[r][c] = 1;
    cnt++;
    if (!chk[r][c-1] && map[r][c-1] == 0) dfs(r, c - 1);
    if (!chk[r][c+1] && map[r][c+1] == 0) dfs(r, c + 1);
    if (!chk[r+1][c] && map[r+1][c] == 0) dfs(r + 1, c);
    if (!chk[r-1][c] && map[r-1][c] == 0) dfs(r - 1, c);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    memset(map, -1, sizeof(map));
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == 0) cout << 0;
            else {
                cnt = 0;
                map[i][j] = 0;
                memset(chk, 0, sizeof(chk));
                dfs(i, j);
                map[i][j] = 1;
                cout << cnt;
            }
        }
        cout << '\n';
    }
}