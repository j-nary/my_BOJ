//BOJ_2252 줄 세우기 [골드 3]
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> order[32003];
int inDeg[32003];
queue<int> q;
vector<int> res;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    //입력 받기
    int N, M; cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        order[x].push_back(y);
        inDeg[y]++;
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
        cout << res[i] << ' ';
    }
    cout << '\n';
}