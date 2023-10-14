//BOJ_1743 음식물 피하기 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool T[102][102];
vector<pair<int, int>> trash;
int N, M, K, cnt;
bool visited[102][102];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void DFS(int r, int c) {
    visited[r][c] = true;
    cnt++;

    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        if (!T[nr][nc]) continue;
        if (!visited[nr][nc]) DFS(nr, nc);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        int r, c; cin >> r >> c;
        T[r][c] = true;
        trash.push_back({r, c});
    }

    int ans = 0;
    for (int i = 0; i < K; i++) {
        int r = trash[i].first;
        int c = trash[i].second;
        if (!visited[r][c]) {
            DFS(r, c);
        }
        ans = max(cnt, ans);
        cnt = 0;
    }

    cout << ans << '\n';
}