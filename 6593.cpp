//BOJ_6593 상범 빌딩 [골드 5]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

bool Building[32][32][32]; //# : 0, . : 1
bool chk[32][32][32];
struct node {
    int f, r, c, d;
    //층, 행, 열, 깊이
    bool operator==(const node& other) const {
        return f==other.f && r==other.r && c==other.c;
    }
};
int dir[6][3] = {{0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}, {1, 0, 0}, {-1, 0, 0}};
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    while(1) {
        int L, R, C; cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) break;

        memset(Building, 0, sizeof(Building));
        memset(chk, false, sizeof(chk));
        queue<node> q;
        node E;
        for (int i = 1; i <= L; i++) {
            for (int j = 1; j <= R; j++) {
                for (int k = 1; k <= C; k++) {
                    char ip; cin >> ip;
                    if (ip == 'S') {
                        q.push({i, j, k, 0});
                        chk[i][j][k] = true;
                    } else if (ip == '.') {
                        Building[i][j][k] = 1;
                    } else if (ip == 'E') {
                        E = {i, j, k, 0};
                        Building[i][j][k] = 1;
                    }
                }
            }
        }

        int ans = -1;
        while(!q.empty()) {
            int f = q.front().f;
            int r = q.front().r;
            int c = q.front().c;
            int d = q.front().d;
            q.pop();
            if (E == node({f, r, c, 0})) {
                ans = d;
                break;
            }
            
            for (int i = 0; i < 6; i++) {
                int nf = dir[i][0] + f;
                int nr = dir[i][1] + r;
                int nc = dir[i][2] + c;

                if (!Building[nf][nr][nc]) continue;
                if (chk[nf][nr][nc]) continue;
                chk[nf][nr][nc] = true;
                q.push({nf, nr, nc, d + 1});
            }
        }

        if (ans > 0) {
            cout << "Escaped in " << ans << " minute(s).\n";
        } else {
            cout << "Trapped!\n";
        }
    }
}