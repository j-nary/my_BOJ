//BOJ_3197 백조의 호수 [플래티넘 5]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

char lake[1502][1502];
bool chk[1502][1502];
pair<int, int> parent[1502][1502];
pair<int, int> L1 = {0, 0}, L2 = {0, 0};
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct node {
    int r, c, d;
};
pair<int, int> find(int r, int c) {
    if (parent[r][c] == make_pair(0, 0)) return {r, c};
    return parent[r][c] = find(parent[r][c].first, parent[r][c].second);
}
void merge(pair<int, int> a, pair<int, int> b) {
    a = find(a.first, a.second);
    b = find(b.first, b.second);
    if (a == b) return;
    parent[b.first][b.second] = {a.first, a.second}; 
}
void bfsMerge(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nr = cr + dir[i][0];
            int nc = cc + dir[i][1];

            if (chk[nr][nc]) continue;
            if (lake[nr][nc] == '.' || lake[nr][nc] == 'L') {
                chk[nr][nc] = true;
                q.push({nr, nc});
                merge({cr, cc}, {nr, nc});
            }
        }
    }
}
bool Meeting() {
    return find(L1.first, L1.second) == find(L2.first, L2.second);
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
            if (!chk[i][j]) bfsMerge(i, j);
            if (lake[i][j] == 'X') continue;
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
                for (int j = 0; j < 4; j++) {
                    int jr = nr + dir[j][0];
                    int jc = nc + dir[j][1];
                    if (lake[jr][jc] == '.' || lake[jr][jc] == 'L') {
                        merge({nr, nc}, {jr, jc});
                    }
                }
            }
        }
        if (Meeting()) {
            cout << d + 1 << '\n';
            break;
        }
    }
}