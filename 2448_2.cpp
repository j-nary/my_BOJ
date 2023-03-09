//BOJ_2448 별 찍기 - 11 [골드 4]

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define nMax 3072

bool star[nMax + 1][2*nMax + 1];

void DivideConquer(int depth, int r, int c) {
    if (depth == 3) {
        //삼각형 그리기
        star[r][c] = true;
        star[r+1][c-1] = true;
        star[r+1][c+1] = true;
        for (int i = -2; i <= 2; i++) {
            star[r + 2][c + i] = true;
        }
        return;
    }

    DivideConquer(depth / 2, r, c);
    int delta = (depth + 1) / 2;
    DivideConquer(depth / 2, r + depth / 2, c - delta);
    DivideConquer(depth / 2, r + depth / 2, c + delta);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    DivideConquer(N, 1, N);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 2 * N - 1; j++) {
            if (star[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}