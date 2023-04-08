//BOJ_1992 쿼드트리
//PS 시험 대비 다시 풀어보기

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int map[65][65];

void DC(int depth, int r, int c) {
    int color = map[r][c];
    int flag = 1;
    for (int i = r; i < r + depth; i++) {
        for (int j = c; j < c + depth; j++) {
            if (i == r && j == c) continue;
            if (color != map[i][j]) {
                flag = 0;
                break;
            }
        }
        if (!flag) break;
    }

    //모두 같은 경우
    if (flag) {
        cout << color;
        return;
    }

    //하나라도 다른 경우
    cout << "(";
    int d = depth / 2;
    DC(d, r, c);
    DC(d, r, c + d);
    DC(d, r + d, c);
    DC(d, r + d, c + d);
    cout << ")";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    DC(N, 1, 1);
    cout << '\n';
}