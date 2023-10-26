//BOJ_1525 퍼즐 [골드 2]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
set<vector<vector<int>>> S;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vector<vector<int>> puz(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> puz[i][j];
        }
    }

    queue<pair<vector<vector<int>>, int>> q;
    S.insert(puz);
    q.push({puz, 0});
    while(!q.empty()) {
        vector<vector<int>> cur = q.front().first;
        int d = q.front().second;
        q.pop();

        int cnt = 1;
        bool flag = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (cur[i][j] != cnt++) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (!flag) {
            cout << d << '\n';
            return 0;
        }
        int r = 0, c = 0;
        flag = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (cur[i][j] == 0) {
                    r = i;
                    c = j;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if (nr < 0 || nr >= 3 || nc < 0 || nc >= 3) continue;
            swap(cur[r][c], cur[nr][nc]);
            if (S.find(cur) == S.end()) {
                q.push({cur, d + 1});
                S.insert(cur);
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        cout << cur[i][j] << " ";
                    }
                    cout << '\n';
                }
            }

            swap(cur[r][c], cur[nr][nc]);
        }
    }

    cout << "-1\n";
}   