//BOJ_14503 로봇 청소기 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int Room[51][51];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >> M;
    int sr, sc, d; cin >> sr >> sc >> d;
    //0북, 1동, 2남, 3서
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Room[i][j];
        }
    }

    int ans = 0;
    while(1) {
        if (Room[sr][sc] == 0) {
            Room[sr][sc] = 2;
            ans++;
        }

        //주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        if (Room[sr][sc + 1] && Room[sr][sc - 1] && Room[sr + 1][sc] && Room[sr - 1][sc]) {
            if (d == 0) {
                if (Room[sr + 1][sc] == 1) break;
                sr = sr + 1;
                continue;
            } else if (d == 1) {
                if (Room[sr][sc - 1] == 1) break;
                sc = sc - 1;
                continue;
            } else if (d == 2) {
                if (Room[sr - 1][sc] == 1) break;
                sr = sr - 1;
                continue;
            } else {
                if (Room[sr][sc + 1] == 1) break;
                sc = sc + 1;
                continue;
            }
        }

        //주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
        while(1) {
            //반시계 방향 회전
            if (d == 0) d = 3;
            else d--;

            if (d == 0 && Room[sr - 1][sc] == 0) {
                sr = sr - 1;
                break;
            } else if (d == 1 && Room[sr][sc + 1] == 0) {
                sc = sc + 1;
                break;
            } else if (d == 2 && Room[sr + 1][sc] == 0) {
                sr = sr + 1;
                break;
            } else if (d == 3 && Room[sr][sc - 1] == 0) {
                sc = sc - 1;
                break;
            }
        }
    }

    cout << ans << '\n';
}