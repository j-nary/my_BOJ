//BOJ_11725 트리의 부모 찾기 [실버 2]
//https://www.acmicpc.net/problem/11725

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int parent[100005];
vector<int> v[100005];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;

    int p, q;
    for (int i = 0; i < N-1; i++) {
        cin >> p >> q;
        v[p].push_back(q);
        v[q].push_back(p);
    }

    queue<int> que;
    for (int i = 0; i < v[1].size(); i++) {
        que.push(v[1][i]);
        parent[v[1][i]] = 1;
        parent[1] = 1;
    }

    while(!que.empty()) {
        int idx = que.front();
        que.pop();

        for (int i = 0; i < v[idx].size(); i++) {
            int tmp = v[idx][i];
            if (parent[tmp] != 0) continue;
            que.push(tmp);
            parent[tmp] = idx;
        }
    }

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }
}