//BOJ_1074 Z [실버 1]
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

//2^15 = 32768
// int map[3000][3000];
int R, C;
int cnt = 0;
int flag = 0;
void DC(int depth, int r, int c) {
    if (flag) return;
    if (depth == 1) {
        if (R == r && C == c) { flag = 1; return; }
        // map[r][c] = cnt++;
        cnt++;
        if (R == r && C == c + 1) { flag = 1; return; }
        // map[r][c + 1] = cnt++;
        cnt++;
        if (R == r + 1 && C == c) { flag = 1; return; }
        // map[r + 1][c] = cnt++;
        cnt++;
        if (R == r + 1 && C == c + 1) { flag = 1; return; }
        // map[r + 1][c + 1] = cnt++;
        cnt++;
        return;
    }

    if (R >= r && R < r + depth && C >= c && C < c + depth) {
        int d = depth / 2;
        DC(d, r, c);
        DC(d, r, c + d);
        DC(d, r + d, c);
        DC(d, r + d, c + d);
    } else {
        cnt += (depth * depth);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    cin >> R >> C;
    DC(pow(2, N), 0, 0);

    cout << cnt << '\n';
}