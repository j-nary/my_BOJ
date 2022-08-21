#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Track {
    int r;
    int c;
    int depth;
    bool isBrk;
};

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int map[1003][1003];
bool Vis[2][1003][1003];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            map[i][j] = tmp[j] - '0';
        }
    }

    queue<Track> q;
    q.push({0, 0, 1, false});
    while (!q.empty()) {
        auto [row, col, dist, flag] = q.front();
        q.pop();

        if (row == N - 1 && col == M - 1) {
            cout << dist << '\n';
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nr = row + dir[i][0];
            int nc = col + dir[i][1];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                if (Vis[flag][nr][nc] == false) {
                    if (map[nr][nc] == 0) {
                        q.push({nr, nc, dist + 1, flag});
                        Vis[flag][nr][nc] = true;
                        // cout << nr << ", " << nc << ", " << flag << '\n';
                    }
                    else if (flag == false && map[nr][nc] == 1) {
                        q.push({nr, nc, dist + 1, true});
                        Vis[flag][nr][nc] = true;
                        // cout << nr << ", " << nc << ", " << flag << '\n';
                    }
                }
            }
        }
    }

    cout << -1 << '\n';
}