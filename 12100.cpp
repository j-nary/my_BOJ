//BOJ_12100 2048(Easy) [골드 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, ans;
int NB[22][22];
void dfs(int depth, int B[22][22]) {
    if (depth == 5) return;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            NB[i][j] = B[i][j];
        }
    }

    //오른쪽
    for (int i = 1; i <= N; i++) {
        for (int j = N; j > 1; j--) {
            int k = j - 1;
            while(!NB[i][k]) k--;
            if (NB[i][j] == NB[i][k]) {
                NB[i][j] *= 2;
                ans = max(ans, NB[i][j]);
                NB[i][k] = 0;
            }
        }
    }
    dfs(depth + 1, NB);

    //왼쪽
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            NB[i][j] = B[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < N; j++) {
            int k = j + 1;
            while(!NB[i][k]) k++;
            if (NB[i][j] == NB[i][k]) {
                NB[i][j] *= 2;
                ans = max(ans, NB[i][j]);
                NB[i][k] = 0;
            }
        }
    }
    dfs(depth + 1, NB);


    //위쪽
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            NB[i][j] = B[i][j];
        }
    }
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i < N; i++) {
            int k = i + 1;
            while(!NB[k][j]) k++;
            if (NB[i][j] == NB[k][j]) {
                NB[i][j] *= 2;
                ans = max(ans, NB[i][j]);
                NB[k][j] = 0;
            }
        }
    }
    dfs(depth + 1, NB);

    //아래쪽
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            NB[i][j] = B[i][j];
        }
    }
    for (int j = 1; j <= N; j++) {
        for (int i = N; i > 1; i--) {
            int k = i - 1;
            while(!NB[k][j]) k--;
            if (NB[i][j] == NB[k][j]) {
                NB[i][j] *= 2;
                ans = max(ans, NB[i][j]);
                NB[k][j] = 0;
            }
        }
    }
    dfs(depth + 1, NB);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    int block[22][22];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> block[i][j];
        }
    }

    dfs(0, block);
    cout << ans << '\n';
}