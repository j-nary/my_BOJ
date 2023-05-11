//BOJ_16946 벽 부수고 이동하기 4 [골드 2]
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
int N, M;
int map[1003][1003];
bool chk[1003][1003];
queue<pair<int, int>> q;
queue<pair<int, int>> w;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void bfs (int sr, int sc) {
    q.push({sr, sc});
    chk[sr][sc] = 1;
    int cnt = 1;

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (map[nr][nc] == 0 && !chk[nr][nc]) {
                q.push({nr, nc});
                cnt++;
            } else if (map[nr][nc] > 0 && !chk[nr][nc]) {
                w.push({nr, nc});
            }

            chk[nr][nc] = 1;
        }
    }

    while(!w.empty()) {
        int r = w.front().first;
        int c = w.front().second;
        w.pop();
        map[r][c] += cnt;
        chk[r][c] = 0;
    }
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

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (map[i][j] == 0 && !chk[i][j]) bfs(i, j);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << map[i][j]%10;
        }
        cout << '\n';
    }
}