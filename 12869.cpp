#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

//dp[x][y][z] : scv체력으로 x, y, z가 중졌을 때의 최소 공격 횟수
int dp[61][61][61];
// int order3[6][2] = {{9, 3, 1}, {9, 1, 3}, {3, 1, 9}, {3, 9, 1}, {1, 9, 3}, {1, 3, 9}};
// 
// int order[2] = {3, 9};
// bool isVis[61][61][61];
int scv[3];
struct Set {int scv1, scv2, scv3;};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int scv_cnt; cin >> scv_cnt;
    for (int i = 0; i < scv_cnt; i++) {
        cin >> scv[i];
    }

    if (scv_cnt == 1) {
        int order[2] = {3, 9};
    }
    else if (scv_cnt == 2) {
        int order[2][2] = {{9, 3}, {3, 9}};
    }
    else {
        int order[6][3] = {{9, 3, 1}, {9, 1, 3}, {3, 1, 9}, {3, 9, 1}, {1, 9, 3}, {1, 3, 9}};
    }

    queue<Set> q;
    q.push({scv[0], scv[1], scv[2]});

    while (!q.empty()) {
        auto [sc1, sc2, sc3] = q.front();
        q.pop();

        if (sc1 && sc2 && sc3) {
            for (int i = 0; i < order[0].length(); i++) {
                
            }
        }
    }
}