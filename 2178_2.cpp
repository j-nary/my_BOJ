#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Track {
    int r, c;
    int depth;
};

int map[102][102];
bool vis[102][102];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
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
    q.push({0, 0, 1});
    vis[0][0] = true;
    while(!q.empty()) {
        auto [r, c, d] = q.front();
        q.pop();
        
        if (r == N - 1 && c == M - 1) {
            cout << d << '\n';
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                if (map[nr][nc] == 1 && vis[nr][nc] == false) {
                    q.push({nr, nc, d + 1});
                    vis[nr][nc] = true;
                }
            }
        }

    }
}