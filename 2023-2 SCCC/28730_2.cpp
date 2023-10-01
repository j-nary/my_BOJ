//BOJ_28730
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool H[102][102];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    if (N % 2 == 1) {   //홀수일 때
        for (int i = 1; i <= N; i++) {
            if (i % 2)
                H[i][1] = 1;
            else
                H[i][N] = 1;
        }
    } else {            //짝수일때
        for (int i = 1; i <= N; i++) {
            if (i % 2)
                H[i][1] = 1;
            else
                H[i][N - 1] = 1;
        }
        // for (int j = 1; j <= N; j++) {
        //     if (i % 2)
        // }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (H[i][j]) cout << '#';
            else cout << '.';
        }
        cout << '\n';
    }
}