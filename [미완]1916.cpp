#include <iostream>
#include <algorithm>
#include <vector>

#define INF 1000000000

using namespace std;
int W[1003][1003];
int length[1003];
int res[1003];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int N, M; cin >> N >> M;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            W[i][j] = INF;
        }
    }
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        W[u][v] = w;
    }

    int start, end;
    cin >> start >> end;

    for (int i = 1; i <= N; i++) {
        length[i] = W[start][i];
        res[i] = W[start][i];
    }
    while(1) {
        //아직 방문하지 않은 정점들 중 거리가 가장 짧은 정점 선택
        int idx = 1, value = length[idx];
        for (int i = 2; i <= N; i++) {
            if (length[i] > 0 && length[i] < length[idx]) {
                idx = i;
                value = length[i];
            }
        }

        //모두 방문했으면 탈출
        if (value == INF || value == -1) break;
        res[idx] = value;

        //해당 정점에서 인접하고 아직 방문하지 않은 정점들의 거리 갱신
        for (int i = 1; i <= N; i++) {
            int tmp = length[idx] + W[idx][i];
            if (length[i] > 0 && tmp < length[i]) {
                length[i] = tmp;
            }
        }

        res[idx] = length[idx]; //결과 저장
        length[idx] = -1;       //이미 확정된 노드임을 표시
    }

    cout << res[end] << endl;
}