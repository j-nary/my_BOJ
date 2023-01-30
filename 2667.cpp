//BOJ_2667 단지번호붙이기 [실버 1]
//https://www.acmicpc.net/problem/2667

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int map[30][30];
bool check[30][30];
vector<int> res;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    queue<pair<int, int>> q;
    while(1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 1 && !check[i][j]) {
                    q.push({i, j});
                    check[i][j] = 1;
                    break;
                }
            }
            if (!q.empty()) break;
        }
        if (q.empty()) break;
        int cnt = 0;
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            cnt++;

            if (y > 0 && !check[x][y-1] && map[x][y-1]) {
                q.push({x, y-1});
                check[x][y-1] = 1;
            }
            if (!check[x][y+1] && map[x][y+1]) {
                q.push({x, y+1});
                check[x][y+1] = 1;
            }
            if (x > 0 && !check[x-1][y] && map[x-1][y]) {
                q.push({x-1, y});
                check[x-1][y] = 1;
            }
            if (!check[x+1][y] && map[x+1][y]) {
                q.push({x+1, y});
                check[x+1][y] = 1;
            }

        }
        res.push_back(cnt);
    }

    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}