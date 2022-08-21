/* Æ²·È½À´Ï´Ù. */

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct point { int x, y; };

int map[102][102];
int dist[102][102];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
point check[102][102];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    queue<pair<int, int>> q;
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            map[i][j] = tmp[j] - '0';
        }
    }

    q.push({0, 0});
    while(1) {
        auto [r, c] = q.front();
        q.pop();

        if (r == N - 1 && c == M - 1) break;

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            
            if (nr == check[r][c].x && nc == check[r][c].y) continue;
            if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                if (map[nr][nc] == 1) {
                    q.push({nr, nc});
                    check[nr][nc] = {r, c};
                    if (dist[nr][nc] != 0)
                        dist[nr][nc] = min(dist[nr][nc], dist[r][c] + 1);
                    else
                        dist[nr][nc] = dist[r][c] + 1;
                }
            }
        }
    }

    cout << dist[N-1][M-1] + 1 << '\n';
}