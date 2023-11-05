//BOJ_3197 백조의 호수 [플래티넘 5]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

char lake[1502][1502];
bool chk[1502][1502];
pair<int, int> L1 = {0, 0}, L2 = {0, 0};
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct node {
    int r, c, d;
};
bool Meeting() {
    memset(chk, 0, sizeof(chk));
    queue<pair<int, int>> q;
    q.push(L1);
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (L2 == make_pair(nr, nc)) {
                return true;
            }
            if (lake[nr][nc] != '.') continue;
            if (!chk[nr][nc]) {
                chk[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int R, C; cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> lake[i][j];
            if (lake[i][j] == 'L' && L1 == make_pair(0, 0)) L1 = {i, j};
            else if (lake[i][j] == 'L' && L2 == make_pair(0, 0)) L2 = {i, j};
        }
    }
    
    queue<node> q;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (lake[i][j] != '.') continue;
            for (int k = 0; k < 4; k++) {
                int ni = i + dir[k][0];
                int nj = j + dir[k][1];
                if (lake[ni][nj] == 'X') {
                    q.push({i, j, 0});
                    break;
                }
            }
        }
    }

    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int d = q.front().d;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if (lake[nr][nc] == 'X') {
                lake[nr][nc] = '.';
                q.push({nr, nc, d + 1});
            }
        }
        if (Meeting()) {
            cout << d + 1 << '\n';
            break;
        }
    }
}