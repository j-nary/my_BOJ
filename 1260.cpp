#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> vec[1003];
queue<int> q;
bool check[1003];

void DFS(int);
void BFS(int);

int main() {
    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);

    int a, b;
    for (int i=0; i < M; i++) {
        scanf("%d %d", &a, &b);
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
        sort(vec[i].begin(), vec[i].end());

    DFS(V);
    printf("\n");
    BFS(V);
    printf("\n");
    return 0;
}

void DFS(int start) {
    printf("%d ", start);
    check[start] = true;
    for (int i = 0; i < vec[start].size(); i++) {
        int K = vec[start][i];
        if (check[K] != true) {
            DFS(K);
        }
    }

    return;
}

void BFS(int start) {
    for (int i = 0; i < 1003; i++)
        check[i] = false;
    q.push(start);
    check[start] = true;
    printf("%d ", start);

    while (!q.empty()) {
        for(int i = 0; i < vec[start].size(); i++) {
            if (check[vec[start][i]] == false) {
                q.push(vec[start][i]);
                check[vec[start][i]] = true;
            }
        }
        q.pop();
        if (!q.empty())
            printf("%d ", q.front());
        start = q.front();
    }

    return;
}