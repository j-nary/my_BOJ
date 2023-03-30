//BOJ_2623 음악프로그램 [골드 3]
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> order[1003];
int inDeg[1003];    //inDeg[i] : 정점 i로 들어오는 edge 수
queue<int> q;
vector<int> res;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    //입력 받기
    int N, M; cin >> N >> M;    //N <= 1,000, M <= 100
    string input;
    int x, y;
    for (int i = 0; i < M; i++) {
        int cnt; cin >> cnt;
        cin >> x;
        for (int j = 1; j < cnt; j++) {
            cin >> y;
            inDeg[y]++;
            order[x].push_back(y);
            x = y;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (inDeg[i] == 0) {
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        int idx = q.front();
        q.pop();
        res.push_back(idx);

        for (int i = 0; i < order[idx].size(); i++) {
            int tmp = order[idx][i];
            inDeg[tmp]--;
            if (inDeg[tmp] == 0) {
                q.push(tmp);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (inDeg[i] > 0) {
            cout << 0 << '\n';
            return 0;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << res[i] << '\n';
    }
}