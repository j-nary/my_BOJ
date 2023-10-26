//BOJ_7562 나이트의 이동 [실버 1]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int dir[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};

struct node {
    int r, c, d;
};
bool chk[302][302];
int BFS() {
    int N; cin >> N;
    int sr, sc, er, ec;
    cin >> sr >> sc >> er >> ec;
    memset(chk, false, sizeof(chk));

    queue<node> q;
    q.push({sr, sc, 0});
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int d = q.front().d;
        q.pop();

        if (r == er && c == ec) return d;

        for (int i = 0; i < 8; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (!chk[nr][nc]) {
                chk[nr][nc] = true;
                q.push({nr, nc, d + 1});
            }
        }
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        cout << BFS() << '\n';
    }
}