//BOJ_6168 Best Grass [실버 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

char G[102][102];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool chk[102][102];
void DFS(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];

        if (G[nr][nc] != '#') continue;
        if (!chk[nr][nc]) {
            chk[nr][nc] = true;
            DFS(nr, nc);
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int R, C; cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> G[i][j];
        }
    }

    int cnt = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (!chk[i][j] && G[i][j] == '#') {
                DFS(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
}