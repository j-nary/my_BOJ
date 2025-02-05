#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int chk[502][502];
vector<int> cnt;
int N, M, landIdx = 1;

struct node { int r, c; };

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void bfs(int cr, int cc, vector<vector<int>> land) {
    queue<node> q;
    q.push({cr, cc});
    chk[cr][cc] = landIdx;

    set<int> col;
    int capacity = 0;
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        capacity++;
        col.insert(c);

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if (chk[nr][nc] || land[nr][nc] != 1) continue;

            chk[nr][nc] = landIdx;
            q.push({nr, nc});
        }
    }

    for (int c: col) cnt[c] += capacity;
}

int solution(vector<vector<int>> land) {
    N = land.size();
    M = land[0].size();
    cnt.resize(M + 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (land[i][j] == 1 && !chk[i][j]) {
                bfs(i, j, land);
                landIdx++;
            }
        }
    }

    sort(cnt.begin(), cnt.end(), greater<>());
    return cnt[0];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  vector<vector<int>> land = {{0, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0}, {1, 1, 0, 0, 0, 1, 1, 0}, {1, 1, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 1, 1}};
  cout << solution(land) << '\n';
}