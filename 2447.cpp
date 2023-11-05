//BOJ_2447 별 찍기 - 10 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool star[10004][10004];

void DC(int depth, int r, int c) {
    if (depth == 1) {
        star[r][c] = true;
        return;
    }

    int nd = depth / 3;
    DC(nd, r, c);
    DC(nd, r, c + nd);
    DC(nd, r, c + nd * 2);
    DC(nd, r + nd, c);
    DC(nd, r + nd, c + nd * 2);
    DC(nd, r + nd * 2, c);
    DC(nd, r + nd * 2, c + nd);
    DC(nd, r + nd * 2, c + nd * 2);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    DC(N, 1, 1);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (star[i][j]) cout << "*";
            else cout << " ";
        }
        cout << '\n';
    }
}