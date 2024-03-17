//BOJ_16926 배열 돌리기 1 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, M, R;
int arr[302][302];

void simulate() {
    int tmp[302][302];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            tmp[i][j] = arr[i][j];
        }
    }
    for (int k = 1; k <= min(N, M) / 2; k++) {
        int flag = 1;   // 1 : 좌, 2 : 상, 3 : 우, 4: 하
        
        // top, bottom
        for (int j = k; j <= M - k + 1; j++) {
            if (j != M- k + 1) arr[k][j] = tmp[k][j + 1];
            if (j != k) arr[N - k + 1][j] = tmp[N - k + 1][j - 1];
        }

        // right, left
        for (int i = k; i <= N - k + 1; i++) {
            if (i != N - k + 1) arr[i][M - k + 1] = tmp[i + 1][M - k + 1];
            if (i != k) arr[i][k] = tmp[i - 1][k];
        }

    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> R;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    while (R--) {
        simulate();
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}