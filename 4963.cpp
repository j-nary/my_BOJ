//BOJ_4963 섬의 개수 [실버 2]
//https://www.acmicpc.net/problem/4963

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool map[51][51];
bool check[51][51];
void test_case(int w, int h) {
    memset(check, 0, sizeof(check));
    memset(map, 0, sizeof(map));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> map[i][j];
        }
    }

    queue<pair<int, int>> q;
    int cnt = 0;
    while(1) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] && !check[i][j]) {
                    q.push({i, j});
                    check[i][j] = 1;
                    break;
                }
            }
            if (!q.empty()) break;
        }

        if (q.empty()) break;
        cnt++;

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (y > 0 && map[x][y-1] && !check[x][y-1]) {
                q.push({x, y-1});
                check[x][y-1] = 1;
            }
            if (map[x][y+1] && !check[x][y+1]) {
                q.push({x, y+1});
                check[x][y+1] = 1;
            }
            if (x > 0 && map[x-1][y] && !check[x-1][y]) {
                q.push({x-1, y});
                check[x-1][y] = 1;
            }
            if (map[x+1][y] && !check[x+1][y]) {
                q.push({x+1, y});
                check[x+1][y] = 1;
            }
            if (x > 0 && y > 0 && map[x-1][y-1] && !check[x-1][y-1]) {
                q.push({x-1, y-1});
                check[x-1][y-1] = 1;
            }
            if (y > 0 && map[x+1][y-1] && !check[x+1][y-1]) {
                q.push({x+1, y-1});
                check[x+1][y-1] = 1;
            }
            if (x > 0 && map[x-1][y+1] && !check[x-1][y+1]) {
                q.push({x-1, y+1});
                check[x-1][y+1] = 1;
            }
            if (map[x+1][y+1] && !check[x+1][y+1]) {
                q.push({x+1, y+1});
                check[x+1][y+1] = 1;
            }
        }

    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    while(1) {
        int w, h; cin >> w >> h;
        if (!w && !h) break;
        test_case(w, h);
    }
}