//BOJ_2234 성곽 [골드 3]
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int castle[52][52];
bool chk[52][52];
int hap[2525];    //sum이라는 뜻 ~
int rCnt = 0;
queue<pair<int, int> > q;
int bfs(int sr, int sc) {
    q.push(make_pair(sr, sc));
    chk[sr][sc] = 1;
    int rSize = 0;
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if (r >= N || r < 0 || c >= M || c < 0) continue;
        rSize++;
        
        //Bit Masking 활용하기
        if ((castle[r][c] & 1) == 0 && !chk[r][c - 1]) {    //서쪽
            q.push(make_pair(r, c - 1));
            chk[r][c - 1] = 1;
        }
        if ((castle[r][c] & 2) == 0 && !chk[r - 1][c]) {    //북쪽
            q.push(make_pair(r - 1, c));
            chk[r - 1][c] = 1;
        }
        if ((castle[r][c] & 4) == 0 && !chk[r][c + 1]) {    //동쪽
            q.push(make_pair(r, c + 1));
            chk[r][c + 1] = 1;
        }
        if ((castle[r][c] & 8) == 0 && !chk[r + 1][c]) {    //남쪽
            q.push(make_pair(r + 1, c));
            chk[r + 1][c] = 1;
        }
        castle[r][c] = rCnt;
    }
    return rSize;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int input; cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> castle[i][j];
        }
    }

    int maxrSize = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!chk[i][j]) {
                rCnt++;
                hap[rCnt] = bfs(i, j);
                maxrSize = max(maxrSize, hap[rCnt]);
            }
        }
    }
    cout << rCnt << '\n' << maxrSize << '\n';

    int maxSum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (castle[i][j + 1] && castle[i][j] != castle[i][j + 1])
                maxSum = max(maxSum, hap[castle[i][j]] + hap[castle[i][j + 1]]);
            if (castle[i + 1][j] && castle[i][j] != castle[i + 1][j])
                maxSum = max(maxSum, hap[castle[i][j]] + hap[castle[i + 1][j]]);
        }
    }
    cout << maxSum << '\n';
}