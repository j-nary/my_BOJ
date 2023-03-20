//BOJ_2647 검은점과 하얀점 연결 [플래티넘 3]
//이게 왜 메모리초과야?
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> dpSolve(int, int);
void path(int, int);
const int inf = 100005;
int N;
int dotColor[102];
pair<int, int> dp[102][102];
int idx[102][102];

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    //입력 받기
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%1d", &dotColor[i]);
    }

    //초기값 설정
   for(int i=0; i < N; i++) {
        for(int j = 0; j < N; j++) dp[i][j].first = -1;
    }

    //dfs
    pair<int, int> res = dpSolve(0, N-1);
   cout << res.first << '\n';

    //경로 출력하기
    path(0, N - 1);
}

pair<int, int> dpSolve(int s, int e){
   if(s > e) return {0, 0};
   if(dp[s][e].first != -1) return dp[s][e];

   dp[s][e].first = 0;
   int v = inf, h = 0;

   for(int i = s + 1; i <= e; i += 2){
        if (dotColor[s] == dotColor[i]) continue;

        pair<int, int> left = dpSolve(s+1, i-1);
        pair<int, int> right = dpSolve(i+1, e);
        int tmp = (i - s) + left.first + right.first + (left.second + 1) * 2;
        int height = max(left.second + 1, right.second);

        if ( v == 0 ) {
            v = tmp;
            h = height;
            idx[s][e] = i;
        } else if (v > tmp){
            v = tmp;
            h = height;
            idx[s][e] = i;
        }
   }
   return dp[s][e] = {v, h};
}

void path(int sIdx, int eIdx) {
    if (sIdx > eIdx) return;

    int kIdx = idx[sIdx][eIdx];
    cout << sIdx + 1 << " " << kIdx + 1 << '\n';

    path(sIdx + 1, kIdx - 1);
    path(kIdx + 1, eIdx);
}
