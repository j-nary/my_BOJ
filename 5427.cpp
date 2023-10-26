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

void test_case() {
    int W, H; cin >> W >> H;
    queue<node> q;
    queue<node> f;
    memset(B, 0, sizeof(B));
    memset(chk, 0, sizeof(chk));
    memset(fchk, 0, sizeof(fchk));

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> B[i][j];
            if (B[i][j] == '@') {
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

                if (B[nr][nc] != '.' && B[nr][nc] != '@') continue;
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

            if (r == 1 || r == H || c == 1 || c == W) {
                cout << d + 1 << '\n';
                return;
            }
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if (B[nr][nc] != '.') continue;
                if (chk[nr][nc]) continue;
                chk[nr][nc] = true;
                B[nr][nc] = '@';
                q.push({nr, nc, d + 1});
            }
        }
        depth++;
    }

    cout << "IMPOSSIBLE" << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}