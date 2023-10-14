//BOJ_2583 영역 구하기 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int M, N, K, cnt; //행, 열
bool Paper[102][102];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool visited[102][102];
vector<int> ans;

void DFS(int r, int c) {
    if (r >= M || r < 0 || c >= N || c < 0) return;
    visited[r][c] = true;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        if (nr < 0 || nc < 0) continue;
        if (!visited[nr][nc] && !Paper[nr][nc]) DFS(nr, nc);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) {
                Paper[i][j] = true;
            }
        }
    }

    int ansCnt = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!Paper[i][j] && !visited[i][j]) {
                cnt = 0;
                ansCnt++;
                DFS(i, j);
                ans.push_back(cnt);
            }
        }
    }

    cout << ansCnt << '\n';
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << '\n';
}

//(1,1) (5,2)
// 1 2 3 4 ~ 1