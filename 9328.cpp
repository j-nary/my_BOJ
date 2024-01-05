#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

// . 빈공간 * 벽 $ 훔칠문서 A 문 a 열쇠
char building[102][102];
bool chk[102][102];
bool key[30];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int ans;
queue<pair<int, int>> q;
vector<pair<int, int>> Door[30];

bool pushing(int r, int cc) {
    char c = building[r][cc]; 
    if (c >= 'a' && c <= 'z') {
        key[c - 'a'] = true;
        return true;
    } else if ( c == '.') return true;
    else if (c == '$') {
        ans++;
        return true;
    } else if (c >= 'A' && c <= 'Z') {
        Door[c - 'A'].push_back({r, cc});
        if (key[c - 'A']) return true;
        else return false;
    }

    return false;
}
void test_case() {
    memset(building, 0, sizeof(building));
    memset(chk, false, sizeof(chk));
    memset(key, false, sizeof(key));
    ans = 0;
    // while(!q.empty()) q.pop();
    q = queue<pair<int, int>>();
    for (int i = 0; i < 30; ++i) {
        Door[i].clear();
    }

    int H, W; cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> building[i][j];
        }
    }
    string keys; cin >> keys;
    if (keys != "0") {
        for (int i = 0; i < keys.size(); i++) {
            key[keys[i] - 'a'] = true;
        }
    }
    for (int i = 1; i <= H; i ++) {
        if (!chk[i][1] && pushing(i, 1)) {
            chk[i][1] = true;
            q.push({i, 1});
        }
        if (!chk[i][W] && pushing(i, W)) {
            chk[i][W] = true;
            q.push({i, W});
        }
    }
    for (int j = 0; j <= W + 1; j++) {
        if (!chk[1][j] && pushing(1, j)) {
            chk[1][j] = true;
            q.push({1, j});
        }
        if (!chk[H][j] && pushing(H, j)) {
            chk[H][j] = true;
            q.push({H, j});
        }
    }
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr <= 0 || nc <= 0) continue;
            if (nr > H || nc > W) continue;
            if (chk[nr][nc]) continue;
            chk[nr][nc] = true;

            // 벽인 경우
            if (building[nr][nc] == '*') {
            }

            // 빈공간인 경우
            else if (building[nr][nc] == '.') {
                q.push({nr, nc});
            }

            // 훔칠 문서인 경우
            else if (building[nr][nc] == '$') {
                q.push({nr, nc});
                ans++;
            }

            // 열쇠인 경우
            else if (building[nr][nc] >= 'a' && building[nr][nc] <= 'z') {
                q.push({nr, nc});
                key[building[nr][nc] - 'a'] = true;
                for (int i = 0; i < Door[building[nr][nc] - 'a'].size(); i++) {
                    int dr = Door[building[nr][nc] - 'a'][i].first;
                    int dc = Door[building[nr][nc] - 'a'][i].second;
                    q.push({dr, dc});
                }
            }

            // 문인 경우
            else if (building[nr][nc] >= 'A' && building[nr][nc] <= 'Z') {
                Door[building[nr][nc] - 'A'].push_back({nr, nc}); 
                if (key[building[nr][nc] - 'A']) q.push({nr, nc});
            }          
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}
