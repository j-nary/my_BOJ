//BOJ_1005 ACM Craft[골드 3]
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int Dtime[1003];
int in_degree[1003];
int res[1003];
vector<int> edge[1003];
void test_case() {
    //초기화
    memset(Dtime, 0, sizeof(Dtime));
    memset(in_degree, 0, sizeof(in_degree));
    memset(res, 0, sizeof(res));
    for (int i = 0; i < 1003; i++) {
        edge[i].clear();
    }

    //입력 받기
    int N, K; cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> Dtime[i];
    }
    int X, Y;
    for (int i = 0; i < K; i++) {
        cin >> X >> Y;
        edge[X].push_back(Y);
        in_degree[Y]++;
    }
    int W; cin >> W;
    
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
            res[i] = Dtime[i];
        }
    }

    //위상 정렬 시작!
    int depthCnt = 1;
    while(!q.empty()) {
        int idx = q.front();
        q.pop();

        //queue에서 뽑은 게 W라면
        if (idx == W) break;

        for (int i = 0; i < edge[idx].size(); i++) {
            int tmp = edge[idx][i];
            if (in_degree[tmp] == 0) continue;
            res[tmp] = max(res[tmp], res[idx] + Dtime[tmp]);
            in_degree[tmp]--;
            if (in_degree[tmp] == 0) {
                q.push(tmp);
            }
        }

    }

    cout << res[W] << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}