//BOJ_1987 알파벳 [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

char Board[22][22];
int ans;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void DFS(int r, int c, int depth, string chk) {
    ans = max(ans, depth);

    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        char tmp = Board[nr][nc];
        if (!tmp) continue;
        if (chk[tmp - 'A'] == '1') continue;

        chk[tmp - 'A'] = '1';
        DFS(nr, nc, depth + 1, chk);
        chk[tmp - 'A'] = '0';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int R, C;
    cin >> R >> C;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> Board[i][j];
        }
    }
    string chk = "00000000000000000000000000";
    chk[Board[1][1] - 'A'] = '1';
    DFS(1, 1, 1, chk);
    cout << ans << '\n';
}