//BOJ_1525 퍼즐 [골드 2]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
set<string> S;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string puz;
    char ip;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> ip;
            puz.push_back(ip);
        }
    }

    queue<pair<string, int>> q;
    S.insert(puz);
    q.push({puz, 0});
    while(!q.empty()) {
        string cur = q.front().first;
        int d = q.front().second;
        q.pop();

        int cnt = 1;
        bool flag = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (cur[i*3 +j] != (cnt+'0')) {
                    flag = true;
                    break;
                }
                cnt++;
                if (cnt == 9) break;
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
                if (cur[i*3 +j] == '0') {
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
            swap(cur[r*3 +c], cur[nr*3 +nc]);
            if (S.find(cur) == S.end()) {
                q.push({cur, d + 1});
                S.insert(cur);
            }

            swap(cur[r*3 +c], cur[nr*3 +nc]);
        }
    }

    cout << "-1\n";
}   