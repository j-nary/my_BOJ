//BOJ_5427 불 [골드 4]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

char B[1003][1003];
bool chk[1003][1003];
bool fchk[1003][1003];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct node {
    int r, c, d;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int R, C; cin >> R >> C;
    queue<node> q;
    queue<node> f;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> B[i][j];
            if (B[i][j] == 'S') {
                q.push({i, j, 0});
                chk[i][j] = true;
            } else if (B[i][j] == '*') {
                f.push({i, j, 0});
                fchk[i][j] = true;
            }
        }
    }

    int depth = 0;
    while(!q.empty()) {
        while(!f.empty()) {
            int fr = f.front().r;
            int fc = f.front().c;
            int fd = f.front().d;
            if (fd != depth) break;
            f.pop();

            for (int i = 0; i < 4; i++) {
                int nr = fr + dir[i][0];
                int nc = fc + dir[i][1];

                if (B[nr][nc] != '.' && B[nr][nc] != 'S') continue;
                if (B[nr][nc] == 'D' || B[nr][nc] == 'X') continue;
                if (fchk[nr][nc]) continue;
                fchk[nr][nc] = true;
                f.push({nr, nc, fd + 1});
                B[nr][nc] = '*';
            }
        }

        while(!q.empty()) {
            int r = q.front().r;
            int c = q.front().c;
            int d = q.front().d;
            if (d != depth) break;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if (B[nr][nc] == 'D') {
                    cout << d + 1 << '\n';
                    return 0;
                }
                if (B[nr][nc] != '.') continue;
                if (chk[nr][nc]) continue;
                chk[nr][nc] = true;
                B[nr][nc] = 'S';
                q.push({nr, nc, d + 1});
            }
        }
        depth++;
    }

    cout << "KAKTUS" << '\n';
}