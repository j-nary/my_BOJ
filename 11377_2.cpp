//BOJ_11377 열혈강호 3 [플래티넘 3]
//Maximum Flow로 풀기
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

vector<int> v[2003];
int cap[2003][2003];    //capacity
int flow[2003][2003];   //flow
int path[2003];         //경로 저장
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M, K; cin >> N >> M >> K;
    int cnt;
    int ans = 0, S = 0, T = 2001, B = 2002;   //Source, Sink
    v[S].push_back(B);
    v[B].push_back(S);
    cap[S][B] = cap[B][S] += K;
    for (int i = 1; i <= N; i++) {
        v[S].push_back(i);
        v[i].push_back(S);
        cap[S][i] = cap[i][S] += 1;

        v[B].push_back(i);
        v[i].push_back(B);
        cap[B][i] = cap[i][B] += 1;

        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int input; cin >> input;
            input += N;
            v[i].push_back(input);
            v[input].push_back(i);
            cap[i][input] = cap[input][i] += 1;
        }
    }

    for (int i = 1; i <= M; i++) {
        v[T].push_back(i + N);
        v[i + N].push_back(T);
        cap[T][i + N] = cap[i + N][T] += 1;
    }
    
    while(1) {
        memset(path, -1, sizeof(path));
        queue<int> q;
        q.push(S);

        //augmenting path 구하기
        while(!q.empty() && path[T] == -1) {
            int idx = q.front(); q.pop();

            for (int i = 0; i < v[idx].size(); i++) {
                int nxt = v[idx][i];
                if (cap[idx][nxt] - flow[idx][nxt] > 0 && path[nxt] == -1) {
                    q.push(nxt);
                    path[nxt] = idx;
                    if (nxt == T) break;    //sink에 도달
                }
            }
        }

        //경로 없으니 탈출
        if (path[T] == -1) break;   

        //가장 허용치 낮은 곳 찾기
        int F = 1e9;
        for (int i = T; i != S; i = path[i]) {
            F = min(F, cap[path[i]][i] - flow[path[i]][i]);
        }

        for (int i = T; i != S; i = path[i]) {
            flow[path[i]][i] += F;
            flow[i][path[i]] -= F;      //유량 감쇄
        }
        ans += F;
    }


    cout << ans << '\n';
}