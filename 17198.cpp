// /BOJ_17198 Bucket Brigade

#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

char M[20][20];
bool chk[20][20];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct node {
    int r, c, d;
};
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    queue<node> q;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> M[i][j];
            if (M[i][j] == 'L') {
                q.push({i, j, 0});
                chk[i][j] = true;
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

            if (M[nr][nc] == 'B') {
                cout << d << '\n';
                return 0;
            }
            if (M[nr][nc] != '.') continue;
            if (!chk[nr][nc]) {
                chk[nr][nc] = true;
                q.push({nr, nc, d + 1});
            }
        }
    }


}