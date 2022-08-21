#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct bin {
    int r;
    int c;
    bool isVis;
};

int N, M;
int map[10][10];
int tmp_map[10][10];
bool virus_vis[10][10];
vector<bin> binkan;
vector<pair<int, int>> virus;
vector<pair<int, int>> vec;
queue<pair<int, int>> q;
int res;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve() {
    memset(virus_vis, false, sizeof(virus_vis));
    for (auto [r, c] : virus) {
        q.push({r, c});
        virus_vis[r][c] = true;
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << tmp_map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                if (virus_vis[nr][nc] == false && tmp_map[nr][nc] == 0) {
                    virus_vis[nr][nc] = true;
                    q.push({nr, nc});
                    tmp_map[nr][nc] = 2;
                }
            }            
        }
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // cout << tmp_map[i][j] << " ";
            if (tmp_map[i][j] == 0) sum++;
        }
        // cout << "\n";
    }
    // cout << "\n\n";

    if (res == 0) res = sum;
    else res = max(res, sum);
}

void ComB() {
    if (vec.size() == 3) {
        memcpy(tmp_map, map, sizeof(map));
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << tmp_map[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        for (int i = 0; i < 3; i++) {
            tmp_map[vec[i].first][vec[i].second] = 1;
            // cout << vec[i].first << ", " << vec[i].second << "/";
        }
        // cout << '\n';

        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << tmp_map[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        solve();
        return;
    }

    for (int i = 0; i < binkan.size(); i++) {
        if (binkan[i].isVis) continue;
        vec.push_back({binkan[i].r, binkan[i].c});
        binkan[i].isVis = true;
        ComB();
        vec.pop_back();
        binkan[i].isVis = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0)
                binkan.push_back({i, j, false});
            else if (map[i][j] == 2) {
                virus.push_back({i, j});
                virus_vis[i][j] = true;
            }
        }
    }

    ComB();

    cout << res << '\n';
}