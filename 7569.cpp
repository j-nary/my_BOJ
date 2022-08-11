#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[102][102][102];
bool check[102][102][102];
int dist[102][102][102];
int dir[6][3] = {{0, 0,-1}, {0, 0, 1}, {0, -1, 0}, {0, 1, 0}, {1, 0, 0}, {-1, 0, 0}};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    struct T { int k, i, j; };
    queue<T> q;

    int M, N, H;
    cin >> N >> M >> H;

    for (int k = 0; k < H; k++) {
        for (int i = 0 ; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[k][i][j];
            }
        }
    }

    for (int k = 0; k < H; k++) {
        for (int i = 0 ; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (map[k][i][j] == 1) {
                    q.push({k, i, j});
                    check[k][i][j] = true;
                }
                if (map[k][i][j] == -1) {
                    check[k][i][j] = true;
                }
            }
        }
    }

    while(!q.empty()) {
        int h, r, c;
        h = q.front().k;
        r = q.front().i;
        c = q.front().j;
        q.pop();
        
        for (int i = 0; i < 6; i++) {
            int nh = h + dir[i][0];
            int nr = r + dir[i][1];
            int nc = c + dir[i][2];

            if (nh >= 0 && nh < H && nr >= 0 && nr < M && nc >= 0 && nc < N) {
                if (check[nh][nr][nc] == false) {
                    q.push({nh, nr, nc});
                    dist[nh][nr][nc] = dist[h][r][c] + 1;
                    check[nh][nr][nc] = true;
                }
            }
        }
    }

    int res = 0;
    for (int k = 0; k < H; k++) {
        for (int i = 0 ; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (check[k][i][j] == false) {
                    cout << -1 << '\n';
                    return 0;
                }
                res = max(res, dist[k][i][j]);
            }
        }
    }
    cout << res << '\n';

}