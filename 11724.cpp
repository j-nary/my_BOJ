//BOJ_11724 연결 요소의 개수 
//https://www.acmicpc.net/problem/11724

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool Graph[1003][1003];
bool check[1003];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        Graph[v1][v2] = 1;
        Graph[v2][v1] = 1;
    }

    queue<int> q;
    int cnt = 0;
    while(1) {
        for (int i = 1; i <= N; i++) {
            if (!check[i]) {
                q.push(i);
                check[i] = 1;
                break;
            }
        }

        if (q.empty()) break;
        cnt++;

        while(!q.empty()) {
            int idx = q.front();
            q.pop();

            for (int i = 1; i <= N; i++) {
                if (Graph[idx][i] && !check[i]) {
                    q.push(i);
                    check[i] = 1;
                }
            }
        }
    }

    cout << cnt << endl;
}