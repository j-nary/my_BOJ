//BOJ_2468 안전 영역 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int M[102][102];
bool chk[102][102];
int N, H;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void DFS(int r, int c) {
    chk[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];

        if (chk[nr][nc]) continue;
        if (M[nr][nc] > H) DFS(nr, nc);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> M[i][j];
            H = max(H, M[i][j]);
        }
    }

    int ans = 0;
    while(H--) {
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (M[i][j] <= H) continue;
                if (chk[i][j]) continue;
                DFS(i, j);
                cnt++;
            }
        }
        memset(chk, false, sizeof(chk));
        ans = max(ans, cnt);
    }

    cout << ans << '\n';
}