#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct Node {
    int x, y, power;
    bool operator<(const Node &other) const {
        return power > other.power;
    }
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int powerCost[101][101];

다익스트라야 powerCost 부분만 봐봐

int solution(vector<vector<int>> board, int C) {
    int n = board.size(), m = board[0].size();
    priority_queue<Node> pq;
    fill(&powerCost[0][0], &powerCost[0][0] + 101 * 101, INT_MAX);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 2) {
                pq.push({i, j, 0});
                powerCost[i][j] = 0;
            }
        }
    }
    int ans = INT_MAX;
    while (!pq.empty()) {
        int x = pq.top().x, y = pq.top().y, cost = pq.top().power;
        pq.pop();
        if (board[x][y] == 3) {
            ans = min(ans, cost);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            int newPower = cost + 1 + (board[nx][ny] == 1 ? C : 0);
            if (newPower < powerCost[nx][ny]) {
              powerCost[nx][ny] = newPower;
              pq.push({nx, ny, newPower});
            }
        }
    }
    if (ans == INT_MAX) return -1;
    return ans;
}

int main() {
    vector<vector<int>> board = {
        {0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 1, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 3, 0, 0, 0, 1, 0}
    };
    
    int C = 1;  // 추가적인 조건이 필요하다면 적용 가능
    cout << solution(board, C) << endl; // 결과 출력
    return 0;
}


1번 점수 올려볼래? 2번 풀어볼까?