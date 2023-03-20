//BOJ_2647 검은점과 하얀점 연결 [플래티넘 3]
//메모리초과
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool dotColor[102];
int M[102][102];
int P[102][102];
int node[102];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%1d", &dotColor[i]);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            //색상 동일한 것 예외 처리하기
            if (dotColor[i] == dotColor[j]) M[i][j] = -1;
            //차이가 짝수인 것 예외 처리하기 (안에 내포하고 있는 게 짝수 개여야 하므로!)
            if ((j - i) % 2 == 0) M[i][j] = -1;
        }
    }
    //예외처리되지 않은 것 중 내포하고 있는 돌들의 검/흰 비율이 상이한 경우 예외 처리하기
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (M[i][j] == -1) continue;
            int white = 0;
            int black = 0;
            for (int k = i + 1; k < j; k++) {
                if (dotColor[k] == 0) white++;
                else black++;
            }
            if (white != black) M[i][j] = -1;
        }
    }

    //초기값 설정
    for (int i = 1; i < N; i++) {
        if (M[i][i + 1] == 0) M[i][i + 1] = 1;
    }
    queue<int> q;
    for (int diagonal = 2; diagonal <= N; diagonal++) {
        for (int i = 1; i <= N - diagonal; i++) {
            int j = i + diagonal;
            if (M[i][j] == -1) continue;
            for (int k = i + 2; k <= j - 1; k++) {
                if (M[i + 1][k] == -1) continue;
                q.push(k);
            }

            int flag = 1;
            while(!q.empty()) {
                int idx = q.front();
                q.pop();

                if (M[idx + 1][j - 1] == -1) continue;
                int tmp = max(M[i + 1][idx], M[idx + 1][j -1]) + 1;
                if (M[i][j] == 0) {
                    M[i][j] = tmp;
                    P[i][j] = idx;
                    flag = 0;
                }
                else if (M[i][j] > tmp) {
                    M[i][j] = tmp;
                    P[i][j] = idx;
                    flag = 0;
                }
            }
            if (flag) M[i][j] = -1;
        }


    }

    //최소 경로 구하기
    queue<pair<int, int>> qq;
    int resDist = 0;
    int idx = 0;
    for (int i = 2; i <= N; i++) {
        if (P[1][i] == 0) continue;
        qq.push({1, i});
        if (i + 1 < N) qq.push({i + 1, N});

        int dist = 0;
        while(!qq.empty()) {
            int r = qq.front().first;
            int c = qq.front().second;
            qq.pop();

            dist += 2 * M[r][c];
            dist += (c - r);

            if (c - r == 1) continue;
            qq.push({r + 1, P[r][c]});
            if (P[r][c] != c - 1) qq.push({P[r][c] + 1, c - 1});
        }

        if (resDist == 0) {
            resDist = dist;
            idx = i;
        }
        else if (resDist > dist){
            resDist = dist;
            idx = i;
        }
    }
    cout << resDist << '\n';

    //좌표 출력하기
    qq.push({1, idx});
    if (idx + 1 < N) qq.push({idx + 1, N});
    node[1] = idx;
    while(!qq.empty()) {
        int r = qq.front().first;
        int c = qq.front().second;
        qq.pop();
        node[r] = c;

        if (c - r == 1) continue;
        qq.push({r + 1, P[r][c]});
        if (P[r][c] != c - 1) qq.push({P[r][c] + 1, c - 1});
    }
    for (int i = 1; i < N; i++) {
        if (node[i] == 0) continue;
        cout << i << " " << node[i] << '\n';
    }
}