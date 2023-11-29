//BOJ_1194 달이 차오른다, 가자. [골드 1]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

char D[52][52];
struct node {
    int r, c, d, key;
};
vector<int> chk[52][52];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >> M;
    queue<node> q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> D[i][j];
            if (D[i][j] == '0') {
                q.push({i, j, 0, 0 << 6});
                chk[i][j].push_back(0);
            }
        }
    }
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int d = q.front().d;
        int key = q.front().key;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            int v = D[nr][nc];

            bool flag = true;
            for (int i = 0; i < chk[nr][nc].size(); i++) {
                if (chk[nr][nc][i] == key) {
                    flag = false;
                    break;
                }
            }
            if (v == 0 || v == '#') continue;  // 갈 수 없음
            if (v == '1') {
                cout << d + 1 << '\n';
                return 0;
            }
            if (v >= 'A' && v <= 'F') {
                if (key & 1 << (v - 'A')) {
                    if (flag) {
                        q.push({nr, nc, d + 1, key});
                        chk[nr][nc].push_back(key);
                    }
                } else {    // key가 없는 경우
                    continue;
                }
            }
            else if (v == '.' || v == '0') {
                if (flag) {
                    chk[nr][nc].push_back(key);
                    q.push({nr, nc, d + 1, key});
                }
            }

            else if (v >= 'a' && v <= 'f') {     // key 획득
                int nkey = key | (1 << (v - 'a'));
                flag = true;
                for (int i = 0; i < chk[nr][nc].size(); i++) {
                    if (chk[nr][nc][i] == nkey) flag = false;
                }
                if (flag) {
                    chk[nr][nc].push_back(nkey);
                    q.push({nr, nc, d + 1, nkey});
                }
            }
        }
    }

    cout << -1 << '\n';
}