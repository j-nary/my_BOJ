//BOJ_2679 맨체스터의 도로 [플래티넘 3]
//문제해결 기말고사 대비 연습
//포기
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int C[1003][1003], F[1003][1003];
vector<int> adj[1003];
void test_case() { 
    int N, E, A, B;     //정점 개수, 간선 개수, A->B
    cin >> N >> E >> A >> B;
    for (int i = 0; i < E; i++) {
        int U, V, W; cin >> U >> V >> W;
        adj[U].push_back(V, W);
        C[U][V] = C[V][U] += W;
    }

    int ans = 0;

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}