//BOJ_16935 배열 돌리기 3 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, M, R;
int arr[102][102];
int opr[10];

void simulate1() {  // 상하 반전
    for (int j = 1; j <= M; j++) {
        for (int i = 1; i <= N / 2; i++) {
            swap(arr[i][j], arr[N - i + 1][j]);
        }
    }
}
void simulate2() {  // 좌우 반전
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M / 2; j++) {
            swap(arr[i][j], arr[i][M - j + 1]);
        }
    }
}

void simulate3() {  // 오른쪽으로 90도 회전
    int tmp[102][102];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            tmp[i][j] = arr[i][j];
        }
    }

    for (int j = N, p = 1; p <= N; j--, p++) {
        for (int i = 1, q = 1; q <= M; i++, q++) {
            arr[i][j] = tmp[p][q];
        }
    }
    swap(N, M);
}
void simulate4() {  // 왼쪽으로 90도 회전
    int tmp[102][102];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            tmp[i][j] = arr[i][j];
        }
    }

    for (int j = 1, p = 1; p <= N; j++, p++) {
        for (int i = M, q = 1; q <= M; i--, q++) {
            arr[i][j] = tmp[p][q];
        }
    }
    swap(N, M);
}
void simulate5() {  // 1그룹 -> 2그룹
    int tmp[102][102];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            tmp[i][j] = arr[i][j];
        }
    }

    // 1번 그룹
    for (int i = 1; i <= N / 2; i++) {
        for (int j = 1; j <= M / 2; j++) {
            arr[i][j + M / 2] = tmp[i][j];
        }
    }
    // 2번 그룹
    for (int i = 1; i <= N / 2; i++) {
        for (int j = M / 2 + 1; j <= M; j++) {
            arr[i + N / 2][j] = tmp[i][j];
        }
    }
    // 3번 그룹
    for (int i = N / 2 + 1; i <= N; i++) {
        for (int j = M / 2 + 1; j <= M; j++) {
            arr[i][j - M / 2] = tmp[i][j];
        }
    }
    // 4번 그룹
    for (int i = N / 2 + 1; i <= N; i++) {
        for (int j = 1; j <= M / 2; j++) {
            arr[i - N / 2][j] = tmp[i][j];
        }
    }
}
void simulate6() {  // 1그룹 -> 4그룹
    int tmp[102][102];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            tmp[i][j] = arr[i][j];
        }
    }

    // 1번 그룹
    for (int i = 1; i <= N / 2; i++) {
        for (int j = 1; j <= M / 2; j++) {
            arr[i + N / 2][j] = tmp[i][j];
        }
    }
    // 2번 그룹
    for (int i = 1; i <= N / 2; i++) {
        for (int j = M / 2 + 1; j <= M; j++) {
            arr[i][j - M / 2] = tmp[i][j];
        }
    }
    // 3번 그룹
    for (int i = N / 2 + 1; i <= N; i++) {
        for (int j = M / 2 + 1; j <= M; j++) {
            arr[i - N / 2][j] = tmp[i][j];
        }
    }
    // 4번 그룹
    for (int i = N / 2 + 1; i <= N; i++) {
        for (int j = 1; j <= M / 2; j++) {
            arr[i][j + M / 2] = tmp[i][j];
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

    for (int i = 0; i < R; i++) {
        int op; cin >> op;
        switch (op) {
            case 1:
                simulate1();
                break;
            case 2:
                simulate2();
                break;
            case 3:
                simulate3();
                break;
            case 4:
                simulate4();
                break;
            case 5:
                simulate5();
                break;
            case 6:
                simulate6();
                break;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}

// 1 1 2 2 
// 1 1 2 2
// 3 3 4 4 
// 3 3 4 4

// 3 3 1 1
// 3 3 1 1
// 4 4 2 2 
// 4 4 2 2

// 4 4 3 3 
// 4 4 3 3 
// 2 2 1 1 
// 2 2 1 1 

// 2 2 4 4 
// 2 2 4 4 
// 1 1 3 3 
// 1 1 3 3 

// 1 1 2 2 
// 1 1 2 2 
// 3 3 4 4 
// 3 3 4 4

    // for (int i = 0; i < R; i++) {
    //     int op; cin >> op;
    //     opr[op]++;
    // }

    // //1번 : 상하반전
    // if (opr[1] % 2 == 1) simulate1();
    // //2번 : 좌우반전
    // if (opr[2] % 2 == 1) simulate2();
    // //3번 : 오른쪽 90도 회전
    // //4번 : 왼쪽 90도 회전
    // int tr = opr[3] % 4;
    // int tl = opr[4] % 4;
    // if (tr - tl > 0) {
    //     if (tr == 1) simulate3();
    //     else if (tr == 2) simulate2();
    //     else simulate4();
    // } else if (tr - tl < 0) {
    //     if (tl == 1) simulate4();
    //     else if (tl == 2) simulte2();
    //     else simulate3();
    // }
    // //5번 : 1 -> 2
    // //6번 : 1 -> 4
    // tr = opr[5] % 4;
    // tl = opr[6] % 4;
    // if (tr - tl > 0) {
    //     if (tr == 1) simulate5();
    //     else if (tr == 2) simulate2();
    //     else simulate6();
    // } else if (tr - tl < 0) {
    //     if (tl == 1) simulate6();
    //     else if (tl == 2) simulte2();
    //     else simulate5();
    // }