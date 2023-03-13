//BOJ_1074 Z[실버 1]
//메모리 초과 -> 방문했다는 걸 표시하면 안 되나봐...
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool arr[33000][33000];  //2^15 = 32768
int cnt = 0;
int r, c; 

void drawZ(int i, int j) {
    if (r == i && c == j) {
        cout << cnt << '\n';
        return;
    }
    arr[i][j] = cnt++;
    if (r == i && c == j+1) {
        cout << cnt << '\n';
        return;
    }
    arr[i][j + 1] = cnt++;
    if (r == i+1 && c == j) {
        cout << cnt << '\n';
        return;
    }
    arr[i+1][j] = cnt++;
    if (r == i+1 && c == j+1) {
        cout << cnt << '\n';
        return;
    }
    arr[i+1][j+1] = cnt++;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    cin >> r >> c;

    //초기값 설정
    arr[0][0] = -1;
    arr[0][1] = 1;
    arr[1][0] = 2;
    arr[1][1] = 3;
    cnt = 4;
    if (r == 0 && c == 0) {
        cout << "0\n";
        return 0;
    }
    if (r == 0 && c == 1) {
        cout << "1\n";
        return 0;
    }
    if (r == 1 && c == 0) {
        cout << "2\n";
        return 0;
    }
    if (r == 1 && c == 1) {
        cout << "3\n";
        return 0;
    }
    int depth = 2;
    while(1) {
        depth *= 2;
        for (int i = 0; i < depth; i += 2) {
            for (int j = 0; j < depth; j += 2) {
                if (!arr[i][j]) {
                    drawZ(i, j);
                }
            }
        }
        if (depth == pow(2, N)) break;
    }
}
