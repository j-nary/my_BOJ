//BOJ_5014 스타트링크 [실버 1]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

bool chk[1000006];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    //총 F층, 강호 S층, 스타트링크 G층, U층, D층
    queue<pair<int, int>> q;
    q.push({S, 0});
    chk[S] = true;
    while(!q.empty()) {
        int cur = q.front().first;
        int step = q.front().second;
        q.pop();

        if (cur == G) {
            cout << step << '\n';
            return 0;
        }

        int up = cur + U;
        int down = cur - D;

        if (up <= F && !chk[up]) {
            q.push({up, step + 1});
            chk[up] = true;
        }
        if (down > 0 && !chk[down]) {
            q.push({down, step + 1});
            chk[down] = true;
        }
    }
    cout << "use the stairs" << '\n';
}