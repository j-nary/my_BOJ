//BOJ_2578 빙고 [실버 4]
#include <iostream>

using namespace std;

pair<int, int> Board[30];
bool Bingo[5][5];
int num[30];

int checkBingo() {
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         cout << (int)Bingo[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    int cnt = 0;
    bool success = true;

    // 가로 빙고
    for (int i = 0; i < 5; i++) {
        success = true;
        for (int j = 0; j < 5; j++) {
            if (!Bingo[i][j]) {
                success = false;
                break;
            }
        }
        if (success) cnt++;
    }

    //세로 빙고
    for (int j = 0; j < 5; j++) {
        success = true;
        for (int i = 0; i < 5; i++) {
            if (!Bingo[i][j]) {
                success = false;
                break;
            }
        }
        if (success) cnt++;
    }

    //대각선 빙고
    success = true;
    for (int i = 0, j = 0; i < 5; i++, j++) {
        if (!Bingo[i][j]) {
            success = false;
            break;
        }
    }
    if (success) cnt++;
    success = true;
    for (int i = 0, j = 4; i < 5; i++, j--) {
        if (!Bingo[i][j]) {
            success = false;
            break;
        }
    }
    if (success) cnt++;

    return cnt;
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int tmp; cin >> tmp;
            Board[tmp] = {i, j};
        }
    }
    for (int i = 0; i < 5 * 5; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 25; i++) {
        int r = Board[num[i]].first;
        int c = Board[num[i]].second;
        Bingo[r][c] = true;
        if (i >= 11 && checkBingo() >= 3) {
            cout << i + 1 << '\n';
            break;
        }
    }

    return 0;
}

// 1 0 0 0 0
// 1 1 0 0 0
// 1 1 1 1 1
// 1 0 0 1 0
// 1 0 0 0 1

// 1 1 1 1 1
// 0 1 0 1 0
// 0 0 1 0 0
// 0 1 0 1 0
// 1 0 0 0 1