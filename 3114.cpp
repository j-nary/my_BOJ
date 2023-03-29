//BOJ_3114 사과와 바나나 [골드 2]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int appMap[1502][1502];
int banMap[1502][1502];
int dp[1502][1502];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    //입력 받기
    int R, C; cin >> R >> C;
    string input;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> input;
            if (input[0] == 'A') {
                appMap[i][j] = input[1];
            } else {
                banMap[i][j] = input[1];
            }
        }
    }

    
}