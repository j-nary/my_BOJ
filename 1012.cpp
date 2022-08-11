#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
using namespace std;

int M, N, K;
int check[51][51];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<pair<int, int>> v;
int map[51][51];

void baechew(int r, int c) {
    check[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        assert(nr >=0 && nc >= 0);
        if (!check[nr][nc] && map[nr][nc] == 1) {
            check[nr][nc] = 1;
            baechew(nr, nc);
        }
    }
    return;
}

void test_case() {
    memset(check, 0, sizeof(check));
    memset(map, 0, sizeof(map));
    cin >> M >> N >> K;
    v.clear();

    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
        map[x][y] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < K; i++) {
        if (check[v[i].first][v[i].second] == 0) {
            check[v[i].first][v[i].second] = 1;
            baechew(v[i].first, v[i].second);
            cnt++;
        }
    }

    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}