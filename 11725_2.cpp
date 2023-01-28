//BOJ_11725 트리의 부모 찾기 [실버 2]
//https://www.acmicpc.net/problem/11725
//6개월만에 재도전

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> input;
int parent[100005];
queue<int> que;

void sync(int stn) {
    for (int i = 0; i < input.size(); i++) {
        int p = input[i].first;
        int q = input[i].second;
        if (p == stn && parent[q] == 0) {
            parent[q] = p;
            que.push(q);
        }
        else if (q == stn && parent[p] == 0) {
            parent[p] = q;
            que.push(p);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        input.push_back({a, b});
    }
    sort(input.begin(), input.end());

    //초기값
    for (int i = 0; i < N-1; i++) {
        if (input[i].first == 1) {
            parent[input[i].second] = 1;
            que.push(input[i].second);
        }
        else if (input[i].second == 1) {
            parent[input[i].first] = 1;
            que.push(input[i].first);
        }
    }

    while(!que.empty()) {
        int stn = que.front();
        sync(stn);
        que.pop();
    }

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }
}