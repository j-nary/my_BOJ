//BOJ_2647 검은점과 하얀점 연결 [플래티넘 3]
//이게 왜 메모리초과야?
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
int dotColor[102];
pair<int, int> dp[102][102];
int idx[102][102];

pair<int, int> dpSolve(int s, int e){
	if(s > e) return {0, 0};
	if(dp[s][e].first != -1) return dp[s][e];

	dp[s][e].first = 0;
	int v = 0, h = 0;

	for(int i = s + 1; i <= e; i += 2){
        if (dotColor[s] == dotColor[i]) continue;
        pair<int, int> a = dpSolve(s+1, i-1);
        pair<int, int> b = dpSolve(i+1, e);
        int dist = i - s;
        int tmp = a.first + b.first + dist + (a.second + 1) * 2;

        if ( v == 0 ) {
            v = tmp;
            h = max(a.second + 1, b.second);
            idx[s][e] = i;
        } else if (v > tmp){
            v = tmp;
            h = max(a.second+1, b.second);
            idx[s][e] = i;
        }
	}
	return dp[s][e] = {v, h};
}

struct path {
    int s, e;
    path(int s, int e) : s(s), e(e) {}

    bool operator<(const path p) const {
        return this-> s > p.s;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%1d", &dotColor[i]);
    }

	for(int i=0; i <= N; i++) {
        for(int j = 0; j <= N; j++) dp[i][j].first = -1;
    }

    pair<int, int> res = dpSolve(0, N-1);
	cout << res.first << '\n';

    priority_queue<path> q;
    q.push(path(0, N - 1));
    while(!q.empty()) {
        int sIdx = q.top().s;
        int eIdx = q.top().e;
        q.pop();

        cout << sIdx + 1 << " " << eIdx + 1 << '\n';
        if (sIdx + 1 == eIdx) continue;

        int kidx = idx[sIdx][eIdx];
        q.push(path(sIdx + 1, kidx - 1));
        q.push(path(kidx + 1, eIdx));
    }
}
