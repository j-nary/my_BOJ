//BOJ_3190 뱀 [골드 4]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int Dum[102][102];
queue<pair<int, char>> q;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K; cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            Dum[i][j] = -1;
        }
    }
    for (int i = 0; i < K; i++) {
        int r, c; cin >> r >> c;
        Dum[r][c] = 1;  //사과
    }
    int L; cin >> L;
    for (int i = 0; i < L; i++) {
        int X; char C; cin >> X >> C;
        q.push({X, C});
    }

    int sTime = q.front().first;
    char sDir = q.front().second;
    q.pop();

    int r = 1, c = 1, d = 0;
    //동 0, 남 1, 서 2, 북 3
    Dum[r][c] = 2;
    int ans = 0;
    queue<pair<int, int>> tail;
    tail.push({1, 1});
    while(1) {
        if (ans == sTime) {
            if (sDir == 'D') {
                if (d == 3) d = 0;
                else d++;
            } else if (sDir == 'L') {
                if (d == 0) d = 3;
                else d--;
            }
            sTime = q.front().first;
            sDir = q.front().second;
            q.pop();
        }
        ans++;

        if (d == 0) c = c + 1;
        else if (d == 1) r = r + 1;
        else if (d == 2) c = c - 1;
        else r = r - 1;

        if (Dum[r][c] == 0 || Dum[r][c] == 2) break;

        if (Dum[r][c] == -1) {  //사과가 없다면
            int tr = tail.front().first;
            int tc = tail.front().second;
            tail.pop();
            Dum[tr][tc] = -1;
        }
        Dum[r][c] = 2;
        tail.push({r, c});
    }

    cout << ans << '\n';
}