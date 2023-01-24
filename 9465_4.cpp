//BOJ_9465 스티커 [실버 1]
//https://www.acmicpc.net/problem/9465
//결국엔 dp였다.

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

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < 2; i++) {
            if (j == 1) {
                sticker[i][j] += sticker[!i][j - 1];
            }
            else {
                sticker[i][j] += max(sticker[!i][j-1], sticker[!i][j-2]);
            }
        }
    }

    cout << max(sticker[0][n-1], sticker[1][n-1]) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}