//BOJ_1926 그림 [실버 1]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;
bool img[502][502];
bool chk[502][502];

struct node {
    int r, c, d;
};
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int ans = 0;
void bfs(int r, int c) {
    queue<node> q;
    q.push({r, c, 0});
    chk[r][c] = true;
    int cnt = 0;
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int d = q.front().d;
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if (chk[nr][nc] || !img[nr][nc]) continue;
            chk[nr][nc] = true;
            q.push({nr, nc, d + 1});
        }
    }
    ans = max(ans, cnt);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> img[i][j];
        }
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!chk[i][j] && img[i][j]) {
                cnt++;
                bfs(i, j);
            }
        }
    }

    cout << cnt << '\n';
    cout << ans << '\n';
}