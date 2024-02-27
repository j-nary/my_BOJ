//BOJ_14500 테트로미노 [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, M;
int Paper[502][502];
int ans, sum;
void mintShape() {
    // 가로 방향
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M - 3; j++) {
            sum = 0;
            for (int k = 0; k < 4; k++) {
                sum += Paper[i][j + k];
            }
            ans = max(ans, sum);
        }
    }

    // 세로 방향
    for (int i = 1; i <= N - 3; i++) {
        for (int j = 1; j <= M; j++) {
            sum = 0;
            for (int k = 0; k < 4; k++) {
                sum += Paper[i + k][j];
            }
            ans = max(ans, sum);
        }
    }
}
void yellowShape() {
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            sum = 0;
            sum += Paper[i][j];
            sum += Paper[i][j + 1];
            sum += Paper[i + 1][j];
            sum += Paper[i + 1][j + 1];
            ans = max(ans, sum);
        }
    }
}
void redShape() {
    // 가로 방향
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M - 2; j++) {
            sum = 0;
            for (int k = 0; k < 3; k++) {
                sum += Paper[i][j + k];
            }

            int tmp = Paper[i + 1][j];
            tmp = max(tmp, Paper[i + 1][j + 1]);
            tmp = max(tmp, Paper[i + 1][j + 2]);
            tmp = max(tmp, Paper[i - 1][j]);
            tmp = max(tmp, Paper[i - 1][j + 1]);
            tmp = max(tmp, Paper[i - 1][j + 2]);
            sum += tmp;
            ans = max(ans, sum);
        }
    }

    // 세로 방향
    for (int i = 1; i <= N - 2; i++) {
        for (int j = 1; j <= M; j++) {
            sum = 0;
            for (int k = 0; k < 3; k++) {
                sum += Paper[i + k][j];
            }

            int tmp = Paper[i][j + 1];
            tmp = max(tmp, Paper[i + 1][j + 1]);
            tmp = max(tmp, Paper[i + 2][j + 1]);
            tmp = max(tmp, Paper[i][j - 1]);
            tmp = max(tmp, Paper[i + 1][j - 1]);
            tmp = max(tmp, Paper[i + 2][j - 1]);
            sum += tmp;
            ans = max(ans, sum);
        }
    }
}

void greenShape() {
    //가로 방향
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M - 1; j++) {
            sum = 0;
            for (int k = 0; k < 2; k++) {
                sum += Paper[i][j + k];
            }
            int tmp = Paper[i - 1][j] + Paper[i + 1][j + 1];
            tmp = max(tmp, Paper[i - 1][j + 1] + Paper[i + 1][j]);
            sum += tmp;
            ans = max(ans, sum);
        }
    }
    //세로 방향
    for (int i = 1; i <= N - 1; i++) {
        for (int j = 1; j <= M; j++) {
            sum = 0;
            for (int k = 0; k < 2; k++) {
                sum += Paper[i + k][j];
            }
            int tmp = Paper[i][j - 1] + Paper[i + 1][j + 1];
            tmp = max(tmp, Paper[i + 1][j - 1] + Paper[i][j + 1]);
            sum += tmp;
            ans = max(ans, sum);
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> Paper[i][j];
        }
    }

    mintShape();
    yellowShape();
    redShape();
    greenShape();
    cout << ans << '\n';
}