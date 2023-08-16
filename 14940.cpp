//BOJ_14940 쉬운 최단거리 [실버 1]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int G[1003][1003];
bool chk[1003][1003];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >> M;
    queue<pair<int, int>> q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> G[i][j];
            if (G[i][j] == 2) {
                q.push({i, j});
                G[i][j] = 0;
                chk[i][j] = 1;
            } else if (G[i][j] == 0) {
                chk[i][j] = 1;
            }
        }
    }

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (chk[nr][nc]) continue;
            chk[nr][nc] = 1;
            if (G[nr][nc] == 0) {
                continue;
            }
            G[nr][nc] = G[r][c] + 1;
            q.push({nr, nc});
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!chk[i][j]) cout << "-1 ";
            else cout << G[i][j] << " ";
        }
        cout << '\n';
    }
}