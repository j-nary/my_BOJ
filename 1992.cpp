//BOJ_1992 쿼드트리 [실버 1]

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int video[100][100];

void compress(int depth, int r, int c) {
    if (depth == 1) {
        cout << video[r][c];
        return;
    }

    int tmp = video[r][c];
    bool flag = 0;
    //모두 같으면 0, 하나라도 다르면 1
    for (int i = r; i < r + depth; i++) {
        for (int j = c; j < c + depth; j++) {
            if (tmp != video[i][j]) {
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }

    //모두 같다면
    if (!flag) {
        cout << tmp;
        return;
    }

    //다르다면
    cout << '(';
    int delta = depth / 2;
    compress(delta, r, c);  //좌상
    compress(delta, r, c + delta);  //우상
    compress(delta, r + delta, c);  //좌하
    compress(delta, r + delta, c +delta);   //우하
    cout << ')';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &video[i][j]);
        }
    }

    compress(N, 0, 0);
    cout << '\n';
}