#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

void circuit();

int N, L, R;
int map[51][51];
int map2[51][51];
bool isVis[51][51];
int flag;
int change_flag;
int cnt;
queue<pair<int, int>> q;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void debug() {
        cout << "ha...." << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}

void visbug() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << isVis[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}
void bfs() {
    while (!q.empty()) {
        auto[r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
                int sub = abs(map[nr][nc] - map[r][c]);
                if (sub >= L && sub <= R && !isVis[nr][nc]) {
                    isVis[nr][nc] = true;
                    flag = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    return;
    
}
void realign() {
    int sum = 0;
    int s_cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (isVis[i][j] == true) {
                sum += map[i][j];
                s_cnt++;
            }
        }
    }
    int res = sum / s_cnt;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (isVis[i][j] == true) {
                map2[i][j] = res;
            }
        }
    }

}
void circuit() {
    while(1) {
        memcpy(map, map2, sizeof(map));
        change_flag = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (isVis[i][j] == false) {
                    memset(isVis, false, sizeof(isVis));
                    q.push({i, j});
                    isVis[i][j] = true;
                    bfs();
                    // visbug();
                    if (flag == 1) {
                        change_flag = 1;
                        realign();
                        flag = 0;
                    }
                    else
                        isVis[i][j] = false;
                }
            }
        }
        if (change_flag == 0) return;
        // debug();
        cnt++;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int tmp;
            cin >> tmp;
            map[i][j] = map2[i][j] = tmp;

        }
    }

    circuit();
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << isVis[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << cnt << endl;
}