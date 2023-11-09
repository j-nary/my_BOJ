//BOJ_17071 숨바꼭질 5 [플래티넘 5]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

struct node {
    int x, s; //수빈이의 현재위치, 초
};
int dest[500005];   //dest[i] : 동생이 i번째 있을 때의 시간
bool chk[500005];
bool promising(int x, int s) {
    if (dest[x] < 0) return false;
    if (dest[x] % 2) {  //홀수
        return s % 2;
    } else {    //짝수
        return !(s % 2);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K; cin >> N >> K;
    
    memset(dest, -1, sizeof(dest));
    int idx = K;
    for (int i = 0; ; i++) {
        idx += i;
        if (idx > 500000) {
            idx = i;
            break;
        }
        dest[idx] = i;
    }

    queue<node> q;
    q.push({N, 0});
    while(!q.empty()) {
        int x = q.front().x;
        int s = q.front().s;
        q.pop();

        if (dest[x] == s) {
            cout << s << '\n';
            return 0;
        }
        //걷기
        if (chk[x] && promising(x, s)) {
            if (x > K && x > 1 && s < idx) {
                q.push({x - 1, s + 1});
                chk[x - 1] = true;
            }
            if (x < 500000 && s < idx) {
                q.push({x + 1, s + 1});
                chk[x + 1] = true;
            }
        } else if (!chk[x]) {
            if (x > K && x > 1 && s < idx) {
                q.push({x - 1, s + 1});
                chk[x - 1] = true;
            }
            if (x < 500000 && s < idx) {
                q.push({x + 1, s + 1});
                chk[x + 1] = true;
            }
        }

        //순간이동
        if (2 * x <= 500000 && s < idx && !chk[2 * x]) {
            q.push({2 * x , s + 1});
            chk[2 * x] = true;
        }
    }
    cout << -1 << '\n';
}