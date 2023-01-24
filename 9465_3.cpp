//BOJ_9465 스티커 [실버 1]
//https://www.acmicpc.net/problem/9465
//원래 생각했던 로직에서 오름차순 정렬 후 queue를 이용하기
//응~ 그냥 로직이 틀렸어~

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int sticker[2][100005];
int n;
struct node {
    int value;
    int x;
    int y;
    node(int a, int b, int c) :value(a), x(b), y(c) {}
    bool operator<(const node n) const {
        return this->value < n.value;
    }
};
priority_queue<node> q;
void test_case() {
    cin >> n;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> sticker[i][j];
            q.push(node(sticker[i][j], i, j));
        }
    }

    int sum = 0;

    while(!q.empty()) {
        //최대값 찾기
        int x = q.top().x;
        int y = q.top().y;
        q.pop();
        
        //모두 방문했으면 탈출
        int select = sticker[x][y];
        if (select == -1) continue;
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