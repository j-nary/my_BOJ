//BOJ_1780 종이의 개수 [실버 2]
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int paper[2200][2200];
int res[3];

void sol(int r, int c, int depth) {
    if (depth == 1) {
        res[paper[r][c] + 1]++;
        return;
    }
    int tmp = paper[r][c];
    int flag = 0;
    for (int i = r; i < r + depth; i++) {
        for (int j = c; j < c + depth; j++) {
            if (tmp != paper[i][j]) {
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }

    if (!flag) {
        res[tmp + 1]++;
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sol(r + depth / 3 * i, c + depth / 3 * j, depth / 3);
        }
    }
    
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    sol(0, 0, N);

    cout << res[0] << '\n' << res[1] << '\n' << res[2] << '\n';
}