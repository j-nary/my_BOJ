#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

bool isVis[61][61][61];     //scv체력으로 x, y, z가 중졌을 때의 최소 공격 횟수
struct Set {int sc1, sc2, sc3, cnt;};
int scv[3];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> scv[i];
    }

    queue<Set> q;
    q.push({scv[0], scv[1], scv[2], 0});
    isVis[scv[0]][scv[1]][scv[2]] = true;
    int order[6][3] = {{9, 3, 1}, {9, 1, 3}, {3, 1, 9}, {3, 9, 1}, {1, 9, 3}, {1, 3, 9}};
    int ts1, ts2, ts3;
    memset(isVis, false, sizeof(isVis));

    while (!q.empty()) {
        auto [s1, s2, s3, x] = q.front();
        q.pop();
        // cout << s1 << ", " << s2 << ", " << s3 << ", " << x << endl;

        if (s1 <= 0 && s2 <= 0 && s3 <= 0) {
            cout << x << '\n';
            return 0;
        }

        for (int i = 0; i < 6; i++) {
            ts1 = s1 - order[i][0];
            ts2 = s2 - order[i][1];
            ts3 = s3 - order[i][2];

            if (ts1 < 0) ts1 = 0;
            if (ts2 < 0) ts2 = 0;
            if (ts3 < 0) ts3 = 0;

            if (isVis[ts1][ts2][ts3] == false) {
                q.push({ts1, ts2, ts3, x + 1});
                isVis[ts1][ts2][ts3] = true;
            }
        }
    }
}