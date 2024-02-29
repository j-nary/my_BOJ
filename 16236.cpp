//BOJ_16236 아기 상어 [골드 3]

#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int Sea[22][22];
bool chk[22][22];
struct node {
    int r, c;
    int p, d;
    int cnt;  // N개 먹을 때마다 크기 N+1로 증가
    bool operator<(const node n) const {
        if (this -> d == n.d && this -> r == n.r) return this -> c > n.c;
        else if (this -> d == n.d) return this -> r > n.r;
        return this -> d > n.d;
    }
};
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}}; // 북-서-동-남 순서로
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    memset(Sea, -1, sizeof(Sea));

    int N; cin >> N;
    pair<int, int> baby;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> Sea[i][j];
            if (Sea[i][j] == 9) {
                baby = {i, j};  // 아기상어
                Sea[i][j] = 0;
                chk[i][j] = true;
            }
        }
    }

    // 처음 아기 상어 크기 = 2
    // 상 > 좌
    priority_queue<node> q;
    q.push({baby.first, baby.second, 2, 0, 0});
    int curDepth = 0;
    queue<pair<int, int>> order;
    while (!q.empty()) {
        int r = q.top().r;
        int c = q.top().c;
        int power = q.top().p;
        int depth = q.top().d;
        int cnt = q.top().cnt;
        q.pop();

        if (Sea[r][c] && Sea[r][c] < power) {    // 먹기로 결정
            while(!q.empty()) q.pop();
            int np = (cnt + 1 == power ? 1 : 0);
            power += np;
            cnt = (np ? 0 : cnt + 1);
            memset(chk, false, sizeof(chk));
            order.push({r, c});
            Sea[r][c] = 0;    // 먹고나면 빈 칸이 된다
            curDepth = depth;
        }

        queue<node> tmp;
        bool flag = true;
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (Sea[nr][nc] == -1 || chk[nr][nc] || Sea[nr][nc] > power) {
                chk[nr][nc] = true;
                continue;
            }
            chk[nr][nc] = true;
            if (Sea[nr][nc] == power || Sea[nr][nc] == 0) {
                tmp.push({nr, nc, power, depth + 1, cnt});
            } else if (Sea[nr][nc] < power) {
                q.push({nr, nc, power, depth + 1, cnt});
                flag = false;
                break;
            }
        }
        if (flag) {
            while (!tmp.empty()) {
                q.push(tmp.front());
                tmp.pop();
            }
        }
    }

    cout << curDepth << '\n';
}