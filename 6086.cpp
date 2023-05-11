//BOJ_6086 최대 유량 [골드 3]
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int C[52][52];    //capacity 용량
int F[52][52];    //flow 유량
vector<int> adj[52];   //인접리스트

int Ctoi(char c) {
    if (c <= 'Z') return c-'A';     //0~25
    return c - 'a' + 26;            //26~51
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    char s, e; int w;
    for (int i = 0; i < N; i++) {
        cin >> s >> e >> w;
        int u = Ctoi(s);
        int v = Ctoi(e);
        C[u][v] = C[v][u] += w;
        adj[u].push_back(v);
        adj[v].push_back(u);    //역방향 간선 추가
    }

    int ans = 0, S= Ctoi('A'), T = Ctoi('Z');
    //ans : 총 유량, S : Source, T : Sink
    int path[52];   //경로 기억하는 배열

    while(1) {
        //증가 경로 BFS로 찾기
        memset(path, -1, sizeof(path));
        queue<int> q;
        q.push(S);

        while(!q.empty() && path[T] == -1) {
            int idx = q.front();
            q.pop();

            for (int i = 0; i < adj[idx].size(); i++) {
                int nxt = adj[idx][i];
                if (C[idx][nxt] - F[idx][nxt] > 0 && path[nxt] == -1) {
                    q.push(nxt);
                    path[nxt] = idx;
                    if (nxt == T) break;    //sink에 도달
                }
            }
        }

        if (path[T] == -1) break;   //경로 없으니 탈출
        //가장 허용치 낮은 곳 찾기
        int flow = 1e9;
        for (int i = T; i != S; i = path[i]) {
            flow = min(flow, C[path[i]][i] - F[path[i]][i]);
        }
        for (int i = T; i != S; i = path[i]) {
            F[path[i]][i] += flow;
            F[i][path[i]] -= flow;  //유량 감쇄
        }
        ans += flow;
    }

    cout << ans << '\n';
}