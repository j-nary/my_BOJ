//BOJ_9465 스티커 [실버 1]
//https://www.acmicpc.net/problem/9465
//시간초과의 굴레에 갇힌 날

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sticker[2][100005];
int n;
void test_case() {
    cin >> n;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> sticker[i][j];
        }
    }

    int sum = 0;

    while(1) {
        //최대값 찾기
        pair<int, int> maxIdx = make_pair(0, 0);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                if (sticker[maxIdx.first][maxIdx.second] < sticker[i][j]) {
                    maxIdx = make_pair(i, j);
                }
            }
        }

        int x = maxIdx.first;
        int y = maxIdx.second;
        //모두 방문했으면 탈출
        int select = sticker[x][y];
        if (select == -1) break;
        else {
            sum += select;
            sticker[x][y] = -1;
        }

        //선택된 것 상하좌우 삭제
        if (x == 0) {
            if (y == 0) {
                sticker[x + 1][y] = -1;
                sticker[x][y + 1] = -1;
            }
            else {
                sticker[x][y - 1] = -1;
                sticker[x][y + 1] = -1;
                sticker[x + 1][y] = -1;
            }
        }
        else {
            if (y == 0) {
                sticker[x - 1][y] = -1;
                sticker[x][y + 1] = -1;
            }
            else {
                sticker[x][y - 1] = -1;
                sticker[x][y + 1] = -1;
                sticker[x - 1][y] = -1;
            }
        }
    } 
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}