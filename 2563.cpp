//BOJ_2563 색종이 [실버 5]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int canvas[102][102];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int paper; cin >> paper;
    for (int k = 0; k < paper; k++) {
        int x, y; cin >> x >> y;
        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                canvas[i][j] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (canvas[i][j] == 1) cnt++;
        }
    }

    cout << cnt << endl;
}