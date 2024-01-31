//BOJ_11660 구간 합 구하기 5 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int arr[1024][1024];
int pSum[1024][1024];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        pSum[i][0] = arr[i][0];
        for (int j = 1; j < N; j++) {
            pSum[i][j] = pSum[i][j - 1] + arr[i][j];
        }
    }
    for (int j = 0; j < N; j++) {
        for (int i = 1; i < N; i++) {
            pSum[i][j] += pSum[i - 1][j];
        }
    }
    int x1, y1, x2, y2;
    for (int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        long long res = pSum[x2][y2];
        if (x1 - 1 >= 0) res -= pSum[x1 - 1][y2];
        if (y1 - 1 >= 0) res -= pSum[x2][y1 - 1];
        if (x1 - 1 >= 0 && y1 - 1 >= 0) res += pSum[x1 - 1][y1 - 1];
        cout << res << '\n';
    }
}

// 1 3 6 10
// 2 5 9 14
// 3 7 12 18
// 3 9 15 22

// 1 3  6  10
// 3 8  15 24
// 6 15 27 42
// 9 24 42 64
