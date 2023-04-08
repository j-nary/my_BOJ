//BOJ_2448 별찍기 - 11 [골드 4]
//PS 시험 대비 다시 풀어보기

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool star[3 * 1024 + 2][3 * 1024 * 2 + 2];

void DC(int depth, int r, int c) {
    //삼각형 그리기
    if (depth == 3) {
        star[r][c] = true;
        star[r + 1][c - 1] = true;
        star[r + 1][c + 1] = true;
        for (int i = -2; i <= 2; i++) {
            star[r + 2][c + i] = true;
        }
        return;
    }

    DC(depth / 2, r, c);
    DC(depth / 2, r + depth / 2, c - depth / 2);
    DC(depth / 2, r + depth / 2, c + depth / 2);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    DC(N, 1, N);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 2 * N - 1; j++) {
            if (star[i][j] == true) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << '\n';
    }
}