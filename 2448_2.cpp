//BOJ_2448 별 찍기 - 11 [골드 4]

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define nMax 3072

bool star[nMax][2*nMax];

void DivideConquer(int depth, int x, int y) {
    if (depth == 3) {
        //삼각형 그리기
        star[x][y] = true;
        star[x-1][y-1] = true;
        star[x+1][y-1] = true;
        for (int i = -2; i <= 2; i++) {
            star[x + i][y-2] = true;
        }
        return;
    }

    DivideConquer(depth / 2, x, y);
    int delta = (depth + 1) / 2;
    DivideConquer(depth / 2, x - delta, y - depth / 2 + 1);
    DivideConquer(depth / 2, x + delta, y - depth / 2 + 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    DivideConquer(N, N, N);

    for (int i = nMax; i > 0; i--) {
        for (int j = 1; j <= nMax; j++) {
            if (star[j][i]) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}