//BOJ_14226 이모티콘 [골드 4]
#include <bits/stdc++.h>
#include <iostream>
#include <queue> 

using namespace std;

struct node {
    int e;  // 현재 이모티콘 개수
    int c;  // 클립보드에 저장된 이모티콘 개수
    int d;  // 깊이
};

bool chk[4000][4000];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int S; cin >> S;
    if (S == 1) {
        cout << 0 << '\n';
        return 0;
    }
    queue<node> q;
    q.push({1, 0, 0});
    chk[1][0] = true;

    while (!q.empty()) {
        int e = q.front().e;
        int c = q.front().c;
        int d = q.front().d;
        q.pop();

        // 클립보드에 저장한다.
        if (!chk[e][e] && e > 0) {
            chk[e][e] = true;
            q.push({e, e, d + 1});
        }

        // 화면에 붙여넣기 한다.
        if (e + c < 4000 && !chk[e + c][c] && c > 0) {
            if (e + c == S) {
                cout << d + 1 << '\n';
                break;
            }
            chk[e + c][c] = true;
            q.push({e + c, c, d + 1});
        }

        // 하나를 삭제한다.
        if (e > 0 && !chk[e - 1][c]) {
            if (e - 1 == S) {
                cout << d + 1 << '\n';
                break;
            }
            chk[e - 1][c] = true;
            q.push({e - 1, c, d + 1});
        }
    }
}